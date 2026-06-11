#include <bits/stdc++.h>
#define MAX 100005
#define ll long long
#define upperlimit 1000100
#define INF 1e18
#define eps 1e-8
#define endl '\n'
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define MOD 1000000007
#define slld(t) scanf("%lld",&t)
#define sd(t) scanf("%d",&t)
#define pd(t) printf("%d\n",t)
#define plld(t) printf("%lld\n",t)
#define mp(a,b) make_pair(a,b)
#define FF first
#define SS second
#define pb(x) push_back(x)
#define vi vector<int>
#define clr(a) memset(a,0,sizeof(a))
#define debug(a) printf("check%d\n",a)
#define csl ios::sync_with_stdio(false);cin.tie(0);
#define fi(a,b,c) for(int i=a;i<b;i=i+c)
#define fj(a,b,c) for(int j=a;j<b;j+=c)
using namespace std;
 
ll gcd(ll n1,ll n2) {
	if(n1%n2==0)return n2;
	return gcd(n2,n1%n2);
}
ll powmod(ll base,ll exponent) {
	ll ans=1;
	while(exponent){
		if(exponent&1)ans=(ans*base)%MOD;
		base=(base*base)%MOD;
		exponent/=2;
	}
	return ans;
}
ll max(ll a,ll b,ll c) {
	return max(a,max(b,c));
}
int max(int a,int b,int c) {
	return max(a,max(b,c));
}

int main()
{
	int n, k;
	sd(n);sd(k);
	int h[n];
	fi(0,n,1)sd(h[i]);
	int dp[n];
	dp[0]=0;
	dp[1]=abs(h[1]-h[0]);
	fi(2,n,1){
		dp[i]=INT_MAX;
		for(int j=1;j<k+1 && j<=i;j++){
			dp[i]=min(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
		}
	}
	cout<<dp[n-1];
}