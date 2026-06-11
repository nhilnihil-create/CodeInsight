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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int32 n = s.size();
  if(s[0] == '0' || s[n-1] == '1'){
    ANS(-1);
    return 0;
  }
  REP(i,n-1){
    if(s[i] != s[n-2-i]){
      ANS(-1);
      return 0;
    }
  }
  int32 pre = 1;
  REP(i,n-1){
    cout << pre << " " << i+2 << endl;
    if(s[i] == '1'){
      pre = i+2;
    }
  }
  return 0;
}