// #08 Leetcode String to Integer (atoi) Solution in C

int myAtoi(char* str) {
	int d, k = 0, negative = 0;

	if (!str) return 0;
 	
	while (*str == ' ') str ++;

	if (*str == '+') {
		str ++;

		negative = 1;
		str ++;
	}

	while (*str >= '0' && *str  < = '9') {
		d = *str - '0';
		str ++;
		if (negative == 0) {
			if (k > (0x7fffffff - d) / 10) {        // possitive number overflow
				return 0x7fffffff;
			}
			k = k * 10 + d;
		} else {
			if (k  <  ((signed)0x80000000 + d) / 10) {    // negative number overflow
				return 0x80000000;
			}
			k = k * 10 - d;
		}
	}
	return k;
}


