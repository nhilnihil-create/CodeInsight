#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s[15];
	int sum=0;
	scanf("%s",s);
	const int len=strlen(s);
	for(int i=0;i<len;i++)
	if(s[i]=='o')
	sum++;
	if(len-sum>7)
	printf("NO");
	else
	printf("YES");
	return 0;
 } 