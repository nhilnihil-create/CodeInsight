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
  int32 n;
  cin >> n;
  vector<int32> a(n),b(n);
  bool flg = true;
  REP(i,n){
    cin >> a[i] >> b[i];
    if(a[i] != b[i])flg = false;
  }
  if(flg){
    ANS(0);
    return 0;
  }
  int64 asum = 0;
  REP(i,n)asum += a[i];
  int64 ans = 0;
  REP(i,n){
    if(a[i] > b[i])
      ans = max(ans, asum - a[i] + a[i] - b[i]);
  }
  ANS(ans);
  return 0;
}