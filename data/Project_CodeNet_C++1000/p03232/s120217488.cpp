#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

const lli e5 = 1 << 20;
const lli mod = 1000000007;

lli n;
lli a[e5];
lli b[e5];
lli ans;

lli powl(lli x,lli r,lli mod = 1000000007){
  lli ret = 1;
  for(;r != 0;r >>= 1){
    if(r&1 != 0) ret *= x,ret %= mod;
    x *= x,x %= mod;
  }
  return ret;
}

lli inverse(lli x,lli mod = 1000000007){
  return powl(x,mod-2,mod);
}

lli factorial(lli n,lli mod = 1000000007){
  static lli dp[100000];
  if(dp[n]) return dp[n];
  if(n == 0) return dp[n] = 1;
  return dp[n] = (n*factorial(n-1))%mod;
}


int main(){
	cin >> n;
	for(lli i = 1;i <= n;i++) cin >> a[i];
	for(lli i = 1;i <= n;i++){
		b[i] = inverse(i);
	}
	for(lli i = 0;i < n;i++){
		b[i+1] += b[i];
		b[i+1] %= mod;
	}
	for(lli i = 1;i <= n;i++){
		lli p = ((b[i]-b[0]+mod)+(b[n-i+1]-b[0]+mod)-b[1]+mod)%mod;
		ans += p*a[i]%mod;
		ans %= mod;
	}
	cout << (ans*factorial(n)%mod) << endl;
}
