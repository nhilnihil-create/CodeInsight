#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>
#include <bitset>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

int main(){
  int H, W; cin >> H >> W;
  vector<string> field(H);
  rep(i, H) cin >> field[i];

  bool flag = true;
  for (int i = 0; i < H; ++i){
    for (int j = 0; j < W; ++j){
      if (field[i][j] == '#'){
        bool tmp = false;
        if (j - 1 >= 0) if (field[i][j - 1] == '#') tmp = true;
        if (j + 1 < W)  if (field[i][j + 1] == '#') tmp = true;
        if (i - 1 >= 0) if (field[i - 1][j] == '#') tmp = true;
        if (i + 1 < H)  if (field[i + 1][j] == '#') tmp = true;
        if (!tmp) flag = false;
      }
    }
  }
  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}
