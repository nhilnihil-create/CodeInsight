#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
#include <iomanip>

// output
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
// utility
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline T chmax(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T chmin(T& a, const T b) { return a = (a > b) ? b : a; }

// type/const
#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;
/* const int MOD = 998244353; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;
struct INIT { INIT(){
  cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}}INIT;


signed main() {
  int H, W; 
  cin >> H >> W;
  
  vector<vector<int>> v(H, vector<int>(W));
  REP(i, H) REP(j, W) cin >> v[i][j];

  vector<string> ans;
  REP(i, H){
    if(i%2 == 0){
      REP(j, W){
        if(i == H-1 && j == W-1) break;
        if(v[i][j]%2){
          if(j != W-1){
            ans.emplace_back(to_string(i+1)+" "+to_string(j+1)+" "+to_string(i+1)+" "+to_string(j+2));
            v[i][j+1]++;
          }else{
            ans.emplace_back(to_string(i+1)+" "+to_string(j+1)+" "+to_string(i+2)+" "+to_string(j+1));
            v[i+1][j]++;
          }
        }
      }
    }else{
      RREP(j, W){
        if(i == H-1 && j == 0) break;
        if(v[i][j]%2){
          if(j != 0){
            ans.emplace_back(to_string(i+1)+" "+to_string(j+1)+" "+to_string(i+1)+" "+to_string(j));
            v[i][j-1]++;
          }else{
            ans.emplace_back(to_string(i+1)+" "+to_string(j+1)+" "+to_string(i+2)+" "+to_string(j+1));
            v[i+1][j]++;
          }
        }
      }
    }
  }

  cout << ans.size() << "\n";
  REP(i, ans.size()){
    cout << ans[i] << "\n";
  }

  return 0;
}