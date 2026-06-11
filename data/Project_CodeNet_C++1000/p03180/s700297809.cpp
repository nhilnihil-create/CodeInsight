#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N;
  cin >> N;

  vector<vector<long long>> a(N, vector<long long>(N));
  for(auto& aa: a){
    for(auto& aaa: aa){
      cin >> aaa;
    }
  }

  // dp[0b00110] := the maximum score with rabbit 1 and 2.
  // ans = dp[(1 << N) - 1]
  vector<long long> dp(1 << N);
  for(int bit = 0; bit < (1 << N); bit++){
    vector<int> idx;
    for(int i = 0; i < N; i++){
      if((bit >> i) & 1){
        idx.push_back(i);
      }
    }
    /*
    cout << bit << '\t';
    for(auto i: idx){
      cout << i << ' ';
    }cout << endl;
    */
    for(int i = 0; i < idx.size(); i++){
      for(int j = i + 1; j < idx.size(); j++){
        dp[bit] += a[idx[i]][idx[j]];
      }
    }
  }
  /*
  for(int bit = 0; bit < (1 << N); bit++){
    cout << bit << '\t' << dp[bit] << endl;
  }
  */

  vector<bool> checked(1 << N);
  function<long long(int)> calc_dp;
  calc_dp = [&](int bit){
              if(checked[bit]){
                return dp[bit];
              }
              for(int subset_bit = (bit - 1) & bit; subset_bit > 0; subset_bit = (subset_bit - 1) & bit){
                int complement_bit = (~subset_bit) & bit;
                dp[bit] = max(dp[bit], calc_dp(subset_bit) + calc_dp(complement_bit));
              }
              checked[bit] = true;
              return dp[bit];
            };
  for(int bit = 0; bit < (1 << N); bit++){
    calc_dp(bit);
  }

  cout << dp[(1 << N) - 1] << endl;
}
