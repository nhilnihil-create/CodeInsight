#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define LL long long
#define inl inline
#define re register
#define MAXN 101000
using namespace std;
char s[MAXN];
int n,ans=MAXN*7;
int main()
{
	scanf("%s",s+1);
	s[0]='_';
	n=strlen(s)-1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]!=s[i-1])
		ans=min(ans,max(i-1,n-i+1));
	}
	cout<<ans;
	return 0;
}

