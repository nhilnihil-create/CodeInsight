#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e6+10;
ll sum_M[MAXN],sum_D[MAXN],sum[MAXN];
char s[MAXN];
int n,q_sum,x;
void solve(int x)
{
	ll ans=0;
	for (int i=1;i<=n;i++)
	 if (s[i]=='C') {
	 	ans+=(sum_D[i]-sum_D[max(i-x,0)])*sum_M[i]-(sum[i]-sum[max(i-x,0)]);
	 }
	printf("%lld\n",ans); 
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=n;i>=1;i--) s[i]=s[i-1];
	for (int i=1;i<=n;i++)
	{
		sum_D[i]=sum_D[i-1]; sum_M[i]=sum_M[i-1];
		if (s[i]=='D') sum_D[i]++; else if (s[i]=='M') sum_M[i]++;
	}
	for (int i=1;i<=n;i++) {
		sum[i]=sum[i-1]; 
		if (s[i]=='D') sum[i]+=sum_M[i];
	}
	scanf("%d",&q_sum);
	for (int i=1;i<=q_sum;i++) {
		scanf("%d",&x); solve(x);
	}
}