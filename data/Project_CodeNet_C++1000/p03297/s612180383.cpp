#include <bits/stdc++.h>
using namespace std;

typedef int_fast32_t int32;
typedef int_fast64_t int64;

const int32 inf = 1e9+7;
const int32 MOD = 1000000007;
const int64 llinf = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define all(obj) (obj).begin(),(obj).end()
#define rall(obj) (obj).rbegin(),(obj).rend()
#define fi first
#define se second
#define pb(a) push_back(a)
typedef pair<int32,int32> pii;
typedef pair<int64,int64> pll;

template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return true; } return false;
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return true; } return false;
}

int64 gcd(int64 a, int64 b){
  if(b == 0)return a;
  return gcd(b,a%b);
}

void solve(){
  int64 a,b,c,d;
  cin >> a >> b >> c >> d;
  if(b > d || a < b){
    Yes(false);
    return;
  }
  int64 g = gcd(b,d);
  int64 mn = llinf;
  if(a < (c+1)){
    mn = a;
  }else{
    mn = a - (a - c - 1) / g * g;
  }
  Yes(mn-b>=0);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int32 t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}