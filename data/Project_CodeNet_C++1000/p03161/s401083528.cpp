#include<bits/stdc++.h>

#define Rushia_mywife ios::sync_with_stdio(0);cin.tie(0);
#define rep(i,head,n) for(int i=(head);i<n;i++)
#define F first
#define S second
#define FF first.first
#define FS first.second
#define SF second.first
#define SS second.second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define all(x) (x).begin(),(x).end()
#define SZ(x) (int)(x).size()
#define mem(x,i) memset((x),(i),sizeof((x)))
#define odd(x) ((x)&1)
#define LG(x) (int)log2((x))

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<long long,long long>;
using ld = long double;

mt19937 mt_rand(time(0));
const int mod = 1000000007;
const int hnum = 998244353;
const ld PI = acos(-1);

#define int long long
int qpow(int x,int powcnt,int tomod){
	int res = 1;
	for(;powcnt;powcnt>>=1,x=(x*x)%tomod)
		if(1&powcnt)res = (res*x)%tomod;
	return (res%tomod);
}
int gcd(int aaa,int bbb){
	return (bbb==0 ? aaa : gcd(bbb,aaa%bbb));
}
int lcm(int aaa,int bbb){
	return (aaa/gcd(aaa,bbb))*bbb;
}
int C(int x){
	return x*(x-1)/2;
}
// --------------------------------------**
const int N = 1e5+10;

int n,k;
int a[N];
int dp[N];

void solve(){
	cin >> n >> k;
	rep(i,1,n+1)
		cin >> a[i];
	dp[1] = 0;
	rep(i,2,n+1){
		dp[i] = (int)1e10;
		for(int j=1;j<=k;j++){
			if(i-j<1)
				break;
			dp[i] = min(dp[i],dp[i-j]+abs(a[i]-a[i-j]));
		}
	}
	cout << dp[n] << '\n';
}

signed main(){
    Rushia_mywife
    //int t; cin >> t;
    //while(t--)
    solve();
}
