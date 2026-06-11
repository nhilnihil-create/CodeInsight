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

const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}


int main() {
  int n;cin>>n;
  vector<ll> a(n),b(n);
  rep(i,n)cin>>a[i];
  rep(i,n)cin>>b[i];
  ll summ=0;
  ll sump=0;
  rep(i,n){
    ll x=(a[i]-b[i]);
    if(x>0)sump+=x;
    else summ+=-x/2;
  }
  if(sump<=summ)cout<<"Yes";
  else cout<<"No";
}
