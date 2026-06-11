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
  vector<int> a = {1};
  int tmp = 6;
  for (int i = 1; i <= 7; ++i) {
    a.push_back(tmp);
    tmp *= 6;
  }
  tmp = 9;
  for (int i = 1; i<= 6; ++i){
    a.push_back(tmp);
    tmp *= 9;
  }
  sort(a.begin(), a.end());
  vector<int> dp(N + 1, INF);
  dp[0] = 0;
  for (int i = 0; i < N; ++i){
    for (int j = 0; j < (int)a.size(); ++j){
      if (i + a[j] <= N) dp[i + a[j]] = min(dp[i + a[j]], dp[i] + 1);
    }
  }
  cout << dp[N] << endl;
}
