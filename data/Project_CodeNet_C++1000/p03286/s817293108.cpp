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


int main() {
  ll n;cin >> n;
  if(!n){cout <<0;return 0;}
  string s;
  while(n!=1){
    s.pb(char(abs(n%2)+'0'));
    if(n>0)n=n/(-2);
    else n=(n-1)/(-2);
  }
  s.pb('1');
  reverse(ALL(s));
  cout <<s;
}