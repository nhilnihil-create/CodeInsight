#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  if(s[0] != 'A'){
    cout << "WA\n";
    return 0;
  }
  int32 idx = -1;
  FOR(i,2,s.size()-1){
    if('A' <= s[i] && s[i] <= 'Z'){
      idx = i;
      break;
    }
  }
  if(idx == -1){
    cout << "WA\n";
    return 0;
  }
  FOR(i,1,s.size()){
    if(i == idx)continue;
    if('A' <= s[i] && s[i] <= 'Z'){
      cout << "WA\n";
      return 0;
    }
  }
  cout << "AC\n";
  return 0;
}