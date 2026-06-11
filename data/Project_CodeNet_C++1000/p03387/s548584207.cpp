#include <stdio.h>

int main()
{	 
	int a, b, c, s = 0; 
	
	scanf("%d%d%d", &a, &b, &c);
	if(a > b) a ^= b, b ^= a, a ^= b;
	if(b > c) b ^= c, c ^= b, b ^= c;
	if(a > b) a ^= b, b ^= a, a ^= b;
	if((b - a) & 1) b++, c++, s++;
	s += ((b - a) >> 1) + c - b;
	printf("%d\n", s);
		
	return 0;
}