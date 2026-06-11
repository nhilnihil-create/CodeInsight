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

int n;

ll getsad(ll x,vector<ll> y){
  ll sad=0;
  rep(i,y.size()){
    sad+=(ll)abs(y[i]-x);
  }
  return sad;
}

int main() {
  cin >> n;
  ll sum=0;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
    a[i]-=(i+1);sum+=a[i];
  }
  sort(ALL(a));
  ll center=a[n/2];
  cout << getsad(center,a);
}