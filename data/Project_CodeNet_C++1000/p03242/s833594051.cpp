#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	char s[8];
	scanf("%s",s);
	for(int i=0;i<3;i++)
		if(s[i]=='1')s[i]='9';
		else s[i]='1';
	printf("%s",s);
}
