#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define INF (1 << 30) - 1
#define LINF 1LL << 60
const int MOD = 1000000007;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  for(int i = 0; i < n; ++i){
    cin >> p[i];
  }

  vector<int> dp(n + 1, 0);
  int seq = 0;
  for(int i = 0; i < n; ++i){
    dp[p[i]] = dp[p[i] - 1] + 1;
    seq = max(seq, dp[p[i]]);
  }

  cout << n - seq << endl;

  return 0;
}
