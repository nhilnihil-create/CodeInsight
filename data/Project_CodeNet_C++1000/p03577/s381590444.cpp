#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char s[10010];
	scanf("%s",s);
	int len=strlen(s);
	s[len-8]='\0';
	cout<<s;
	return 0;
}