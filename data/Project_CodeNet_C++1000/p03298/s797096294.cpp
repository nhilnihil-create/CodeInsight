#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int mod=20010531;
const int N=20;
typedef long long ll;
int t[N],n,a[N],b[N];
ll ans;
char s[N*2];
map<P,int> mp;
void dfs1(int x)
{
	if (x==n+1)
	{
		int s1=0,s2=0;
		for (int i=1;i<=n;i++)
		  if (t[i]) s1=((ll)s1*31%mod+a[i])%mod;
		  else s2=((ll)s2*31%mod+a[i])%mod;
		mp[P(s1,s2)]++;
		return;
	}
	t[x]=0;dfs1(x+1);
	t[x]=1;dfs1(x+1);
}
void dfs2(int x)
{
	if (x==n+1)
	{
		int s1=0,s2=0;
		for (int i=n;i>=1;i--)
		  if (t[i]) s1=((ll)s1*31%mod+b[i])%mod;
		  else s2=((ll)s2*31%mod+b[i])%mod;
		if (mp.count(P(s1,s2))) ans+=mp[P(s1,s2)];
		return;
	}
	t[x]=0;dfs2(x+1);
	t[x]=1;dfs2(x+1);
}
int main()
{
	scanf("%d%s",&n,s+1);
	for (int i=1;i<=n;i++) a[i]=s[i]-'a'+1;
	for (int i=n+1;i<=2*n;i++) b[i-n]=s[i]-'a'+1;
	dfs1(1);dfs2(1);
	printf("%lld\n",ans);
	return 0;
}