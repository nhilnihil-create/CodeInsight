#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323
#define ll long long int
#define vi vector <int>
#define vl vector <ll>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define MOD 1000000007
ll power(ll a, ll b) { //a^b
	ll res = 1;
	while (b > 0) {
		if (b & 1) {res = (res * a); b--;}
		a = (a * a);
		b >>= 1;
	}
	return res;
}
ll n;
ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}


int main() {
	ll n,k;
	cin>>n>>k;
	vector <ll> a(n+1);
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	vector < vector <ll> > dp(n+1, vector <ll> (k+1));
	
	for(ll j=0;j<=k;j++)
		dp[0][j]=0;
	dp[0][0]=1;
	for(ll i=1;i<=n;i++){
		vector <ll> pre(k+1);
		pre[0]=dp[i-1][0];
		for(ll j=1;j<=k;j++)
			pre[j]=(pre[j-1]+dp[i-1][j])%MOD;
		for(ll j=0;j<=k;j++){
			if(j<=a[i])
				dp[i][j]=pre[j];
			else{
				ll non=j-a[i]-1;
				dp[i][j]=(pre[j]-pre[non]+MOD)%MOD;
			}
		}
	}
	cout<<dp[n][k]<<"\n";
}
