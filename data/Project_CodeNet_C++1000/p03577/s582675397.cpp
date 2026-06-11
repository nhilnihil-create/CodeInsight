#include<bits/stdc++.h>
using namespace std;
char s[51];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	for (int i=0;i<len-8;i++)
	  printf("%c",s[i]);
	return 0;
}