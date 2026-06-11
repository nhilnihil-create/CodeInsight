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
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

int main(){
  int N; cin >> N;
  string S; cin >> S;
  int n = S.length();

  //S[0:i], S[i+1:end]
  int ans = 0;
  for (int i = 1; i < n - 1; ++i){
    vector<vector<int>> que(2, vector<int>(26));
    for (int j = 0; j < i; ++j){
      que[0][S[j] - 'a']++;
    }
    for (int j = i; j < n; ++j){
      que[1][S[j] - 'a']++;
    }
    int tmp = 0;
    for (int j = 0; j < 26; ++j){
      if (que[0][j] != 0 && que[1][j] != 0) tmp++;
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
