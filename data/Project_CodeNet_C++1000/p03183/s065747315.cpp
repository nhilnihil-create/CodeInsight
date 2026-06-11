#include<iostream>
#include<tuple>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int N;
  cin >> N;

  vector<tuple<int, int, int>> wsvs(N);
  for(int i = 0; i < N; i++){
    int w, s, v;
    cin >> w >> s >> v;
    wsvs[i] = make_tuple(w, s, v);
  }
  sort(wsvs.begin(), wsvs.end(), [](tuple<int, int, int> a, tuple<int, int, int>b){return get<0>(a) + get<1>(a) < get<0>(b) + get<1>(b);});

  // dp[n][W] := with item[0: n) and the sum of weight <= W, you can get dp[n][W] values
  // dp[0][0] = 0
  // dp[n][W] = max(dp[n - 1][W], dp[n][W - 1]);
  // if s[n - 1] >= W - w[n - 1] then dp[n][W] = max(dp[n][W], dp[n - 1][W - w[n - 1]] + v[n - 1])
  const int w_sum_max = 2e4;
  vector<vector<long long>> dp(N + 1, vector<long long>(w_sum_max + 1, 0));
  for(int n = 0; n <= N; n++){
    dp[n][0] = 0;
  }
  for(int n = 1; n <= N; n++){
    for(int w_sum = 1; w_sum <= w_sum_max; w_sum++){
      int w, s, v;
      tie(w, s, v) = wsvs[n - 1];
      dp[n][w_sum] = max(dp[n - 1][w_sum], dp[n][w_sum - 1]);
      if(s >= w_sum - w && w_sum - w >= 0){
        dp[n][w_sum] = max(dp[n][w_sum], dp[n - 1][w_sum - w] + v);
      }
    }
  }

  cout << dp[N][w_sum_max] << endl;

}
