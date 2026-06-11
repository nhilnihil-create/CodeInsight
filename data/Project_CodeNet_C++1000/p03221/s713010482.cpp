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

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

int main(){
  int N, M; cin >> N >> M;
  vector<int> p(M), y(M);
  rep(i, M) cin >> p[i] >> y[i];
  rep(i, M) --p[i];

  vector<vector<P>> que(N);
  rep(i, M){
    que[p[i]].push_back(make_pair(y[i], i));
  }
  rep(i, N){
    sort(que[i].begin(), que[i].end());
  }

  vector<string> ans(M);
  rep(i, N){
    string str = to_string(i + 1);
    while (str.length() != 6) str = '0' + str;
    int n_city = 1;
    for (auto e: que[i]){
      string str2 = to_string(n_city);
      while (str2.length() != 6) str2 = '0' + str2;
      ans[e.second] = str + str2;
      n_city++;
    }
  }
  rep(i, M) cout << ans[i] << endl;
}
