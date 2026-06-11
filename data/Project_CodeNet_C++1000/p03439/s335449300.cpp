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

int32 n;

map<int32,int32> cache;
int32 query(int32 i){
  if(i == n)i = 0;
  if(cache.count(i))return cache[i];
  cout << i << endl;
  string res;
  cin >> res;
  auto &ret = cache[i];
  if(res == "Vacant"){
    ret = 2;
  }else if(res == "Male"){
    ret = 0;
  }else{
    ret = 1;
  }
  return ret;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  int32 l = 0,r = n/2;
  if(r%2)++r;
  if(query(l) == 2)return 0;
  if(query(r) == 2)return 0;
  if(query(l) == query(r)){
    l = r;
    r = n;
  }
  while(r - l > 2){
    // cout << l << " " << r << endl;
    int32 m = (l + r) / 2;
    if((m-l)%2)++m;
    if(query(m) == 2)return 0;
    if(query(l) == query(m)){
      l = m;
    }else{
      r = m;
    }
  }
  query((l+r)/2);
  return 0;
}