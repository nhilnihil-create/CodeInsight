#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  /////r~lまでの和が0　ー＞　累積和
  int n;
  cin>>n;
  vll a(n);
  rep(i,0,n) cin>>a[i];
  vll sum(n+1,0);
  sum[0]=0;
  rep(i,0,n) sum[i+1]=sum[i]+a[i];
  map<ll,ll> cnt;
  rep(i,0,n+1){
    cnt[sum[i]]++;
  }
  ll ans=0;
  for(auto v:cnt){
    ans+=v.second*(v.second-1)/2;
  }
  cout<<ans<<endl;
}