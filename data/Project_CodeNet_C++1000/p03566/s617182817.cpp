#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>

#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
int n;
double dp[101][101];
int t[101];
int vm[101];

int main(int argc, char const* argv[])
{
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> t[i];
  }
  for(int i = 0; i < n; i++){
    cin >> vm[i];
  }
  for(int i = 0; i < 101; i++){
    for(int j = 0; j < 101; j++){
      dp[i][j] = -1.;
    }
  }
  dp[0][0] = 0.;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 101; j++){
      if(vm[i] < j){
        break;
      }
      dp[i + 1][j] = 0.;
      bool flag = false;
      for(int k = 0; k <= vm[i]; k++){
        if(dp[i][k] < 0)continue;
        double tmp = 0.;
        double at_t = 0.5 * (j - k + t[i]);
        if(at_t < 0 || at_t > t[i])continue;
        flag = true;
        double at_y = k + at_t;
        if(at_y < vm[i])tmp += 0.5 * at_t * (k + at_y) + 0.5 * (t[i] - at_t) * (j + at_y);
        else tmp += 0.5 * (vm[i] - k) * (vm[i] + k) + 0.5 * (vm[i] - j) * (vm[i] + j) + (t[i] - vm[i] + k - vm[i] + j) * vm[i];
        dp[i + 1][j] = max(dp[i + 1][j], tmp + dp[i][k]);
      }
      if(!flag)dp[i + 1][j] = -1.;
    }
  }
  cout << setprecision(12);
  cout << dp[n][0] << endl;
	return 0;
}
