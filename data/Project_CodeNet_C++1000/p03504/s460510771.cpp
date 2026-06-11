#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define RFOR(i,a,b) for(int i = (int)(b-1);i>=(int)(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cout.tie(0);

  int n, C;
  cin >> n >> C;
  vector<vector<P>> a(C);

  REP(i, n){
    int s,t,c;
    cin >> s >> t >> c;
    c--;
    a[c].push_back({s,t});
  }
  REP(i, C) sort(a[i].begin(), a[i].end(), [](P b, P d){
    return b.first < d.first;
  });

  //連続となっている区間の結合
  vector<vector<P>> aa(C);
  REP(i, a.size()) {
    if(a[i].empty()) continue;
    P tmp = a[i][0];
    REP(j, a[i].size() - 1){
      if(tmp.second == a[i][j + 1].first){
        tmp.second = a[i][j + 1].second;//繋がっている番組を結合
      }
      else{
        if(j + 1 < a[i].size() ) {
          aa[i].push_back(tmp);
          tmp = a[i][j + 1];
        }
      }
    }
    aa[i].push_back(tmp);
  }

  //imos法
  vec table(2 * 1e5 + 1, 0);
  REP(i, aa.size()) REP(j, aa[i].size()) {
    table[2 * aa[i][j].first - 1]++;
    table[2 * aa[i][j].second]--;
  }
  FOR(i, 1, table.size()){
    table[i] += table[i - 1];
  }

  cout << *max_element(table.begin(), table.end()) << endl;


  return 0;
}