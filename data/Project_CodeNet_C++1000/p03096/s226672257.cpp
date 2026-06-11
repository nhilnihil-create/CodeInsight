#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 50;
constexpr double pi=3.14159265358979;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
using namespace std;

vector< bool > prime_table(int n) {
  vector< bool > prime(n + 1, true);
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  for(int i = 2; i * i <= n; i++) {
    if(!prime[i]) continue;
    for(int j = i + i; j <= n; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}

int pre[200005];//ある色について今見ている位置より前において、どこに出てきたか
void solve(){
    int n;
    cin>>n;
    vector<ll>dp(n+5,0);
    vector<int>c(n);
    memset(pre,-1,sizeof(pre));
    rep(i,n){
      cin>>c[i];
    }
    dp[0]=1;pre[c[0]]=0;
    for(int i=1;i<n;++i){
      if(c[i-1]==c[i]||pre[c[i]]==-1)dp[i]=dp[i-1];//色が１つ前と同じだったり、はじめてその色が出てきた時は1つ前と方法の数は変わらず
      else dp[i]=(dp[i-1]+dp[pre[c[i]]])%mod;
      pre[c[i]]=i;
    }
    cout<<dp[n-1]<<"\n";
    return;
}

signed main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	solve();
	return 0;
}
