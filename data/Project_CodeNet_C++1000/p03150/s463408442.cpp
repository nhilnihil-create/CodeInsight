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

int div_ct(int n) {
  int c = 0;
  int k;
  for ( k = 1; k <= n; k++ ) { 
    if ( n % k == 0 ) { c++; } 
  }
  return c;
}

int main() {
  string s;cin>>s;
  int n=s.size();
  if(s=="keyence"){cout<<"YES";return 0;}
  reps(i,n)rep(j,n){
    if(i>j)continue;

    string t=s.substr(0,i);
    string u=s.substr(j,n-j+1);
    if(t+u=="keyence"){cout<<"YES";return 0;}
  }
  cout<<"NO";
}
