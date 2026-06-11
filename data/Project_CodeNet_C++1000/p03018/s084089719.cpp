#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

char s[maxn];
ll pre[maxn];

int main()
{
	scanf("%s",s+1); ll len=strlen(s+1),ans=0;
	rep(i,1,len-1)
	{
		if(s[i]=='A') pre[i]=pre[i-1]+1; else pre[i]=0;
		if(s[i]=='B'&&s[i+1]=='C')
		{
			ans+=pre[i-1];
			pre[i]=pre[i-1]-1;
			pre[i+1]=pre[i-1]; i++;
		}
	}
	cout<<ans<<endl;
	return 0;
}