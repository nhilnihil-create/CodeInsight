#include<cstdio>
char a,b;
int main()
{
	scanf("%c %c",&a,&b);
	if(a^b)	
		putchar(a<b?'<':'>');
	else 
		putchar('=');
	return 0;
}