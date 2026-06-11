#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 200005
char s[N];
long long tot=0,suf[N];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	int i=0,lp=0;
	for(;i<len;)
	{
		if(s[i]=='B'&&s[i+1]=='C') tot++,suf[tot]=lp,i+=2;
		else
		{
			if(s[i]=='A') lp++;
			else lp=0;
			i++;
		}
	}
	long long ans=0;
	for(int i=tot;i>=1;i--)
	{
		ans=ans+suf[i];	 
	}
	cout<<ans<<endl;
	
	
	
	
	return 0; 
} 