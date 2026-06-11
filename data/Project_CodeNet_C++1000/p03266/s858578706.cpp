#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i < n; i++)
#define REP(i, n, m) for(int i=n; i < m; i++)
#define reps(i, n) for(int i=1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

using namespace std;
using ll=long long;

ll mod=1000000007;

const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

ll mypow(ll a,int b){
  ll res=1;
  rep(i,b)res*=a;
  return res;
}

int main() {
  int n,k;cin>>n>>k;
  ll x=n/k;ll y=n%k;
  ll ans=mypow(x,3);
  if(k%2){cout << ans;return 0;}
  ans+=(y<k/2?ans:mypow(x+1,3));
  cout << ans;
}