#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> pi;
priority_queue<pi, vector<pi>, greater<pi> > pq; //min heap

#define dodebug(i, n, arr)	for(int i=0;i<n;++i)	cout<<arr[i]<<" ("<<i<<")\n";

ll gcd(ll a,ll b){	if(b == 0)	return a;return gcd(b,a%b);}
ll binpow(ll n,ll x){	ll ans = 1;while(x){if(x & 1)	ans *= n;n *= n;x >>= 1;}return ans;}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;
	vector<double> dp(n+1, 0);

	dp[0] = 1;

	double p;
	for(int i=0;i<n;++i){
		cin>>p;
		for(int j=i+1;j>0;--j)	dp[j] = p*dp[j-1] + (1-p)*dp[j];
		dp[0] = (1-p)*dp[0];
	}
	double ans = 0;
	for(int i=n;i>n/2;--i)	ans += dp[i];

	cout<<setprecision(11)<<ans<<"\n";

	return 0;
}