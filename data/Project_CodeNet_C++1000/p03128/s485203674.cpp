#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  map<int, int> all_nums = {{1,2},{2,5},{3,5},{4,4},{5,5},{6,6},{7,3},{8,7},{9,6}};
  map<int, int> nums;
  
  for(int i=0; i<M; i++) {
    int tmp;
    cin >> tmp;
    nums[tmp] = all_nums[tmp];
  }
  
  /* マッチN本でM個の数から数を作っていく */
  /* dp[n] : n本のマッチでつくることのできる、最大桁数*/
  
  vector<int> dp(N+2,-10000);
  int i = 0;  
  dp[0] = 0;
  dp[1] = 0;
  while(i<=N+1) {
    for(auto num:nums) {
      if(i-num.second<=0) {
        continue;
      }
      int tmp = dp[i-num.second] + 1;
      if(tmp>dp[i]) {
        dp[i] = tmp;
      }
    }  
    i++;
  }
  
  int len = dp[N+1];
  dp.erase(dp.begin());
  
  for(int i=0; i<len; i++) {
    for(auto itr=nums.rbegin(); itr!=nums.rend(); itr++) {
      if(i==len-1) {
        if(N==itr->second) {
          cout << itr->first << endl;
          break;
        }
      } else {
        if(dp[N-itr->second] == dp[N]-1) {
          cout << itr->first;
          N -= itr->second;
          break;
        }
      }
    }
  }
  return 0;
}