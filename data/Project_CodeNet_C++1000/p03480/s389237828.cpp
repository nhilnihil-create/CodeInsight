//C
#include<cstdio> 
#include<iostream>
#include<cstring>
using namespace std;
char s[100010];
int main()
{
	int k=100010,len;
	scanf("%s",s);
	len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]!=s[i+1])
		{
			k=min(k,max(i+1,len-1-i));
		}
	}
	printf("%d",k);
}