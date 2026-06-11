#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;

vector<int> fac(MX);
vector<int> ifac(MX);

long long fpow(long long a,long long n){
  long long ret=1;
  if(n==1) return a;
  if(n%2==0) {
      ret = fpow(a*a%mod, n/2) %mod ;
  }else {
      ret = (a%mod)*fpow(a*a%mod, n/2) %mod;
  }
  return ret %mod;
}

int comb(int a, int b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    int tmp = ifac[a-b]* ifac[b] % mod;
    return tmp * fac[a] % mod;
}

int P(int a, int b) {
    int res = comb(a,b);
    res *= fac[b];
    return res % mod;
}

int ans, k;
vector<int> to[100005];
void dfs(int v, int p=-1) {
    for(int u: to[v]) {
        if(u == p) continue;
        dfs(u, v);
    }
    int nk = (p==-1) ? k : k-2;
    int c = (p==-1) ? to[v].size()+1 : to[v].size()-1;
    ans *= P(nk, c);
    ans %= mod;
}

int dp[MX+5];
signed main(){
    int n;
    cin >> n;
    vector<int> a;
    rep(i, n+1) dp[i]=MX+5;
    dp[0] = 0;
    dp[1] = 1;
    int cnt = 0;
    a.push_back(1);
    for(int i= 6; i<=n; i=i*6) {
        a.push_back(i);
    }
    cnt = 0;
    for(int i= 9; i<=n; i=i*9) {
        a.push_back(i);
    }

    int ans = 0;
    FOR(i, 2, n+1) {
        for(auto aa: a) {
            if(i-aa>=0) dp[i] = min(dp[i-aa]+1, dp[i]); 
        }
    }

    cout << dp[n] << endl;

    return 0;
}


