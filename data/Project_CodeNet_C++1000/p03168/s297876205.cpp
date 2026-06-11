#include<iostream>
#include<bits/stdc++.h>

#define fl(k, n) for(int i = k; i < n; i++)
#define flr(k, n) for(int i = n - 1; i >= k; i--)
#define vi vector<int>
#define vp vector<pair<int, int>>
#define mp make_pair
#define ll long long
#define llu long long unsigned int
#define mod 1000000007

using namespace std;

int binary_search(vector<int> nums, int target_val){
  int begin = 0;
  int end = nums.size();
  int mid;

  while(begin <= end){
    mid = begin + (end - begin) / 2;
    if(nums[mid] == target_val)
      return mid;
    else if(nums[mid] <= target_val && nums[mid + 1] > target_val)
      return mid;
    else if(nums[mid] > target_val)
      end = mid - 1;
    else
      begin = mid + 1;
  }

  if(begin == 0)
    return -1;
  else 
    return nums.size();
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<long double> probs(n);
  fl(0, n)
    cin >> probs[i];

  vector<vector<long double>> dp(n + 1, vector<long double> (n + 1));
  dp[0][0] = 1;

  fl(1, n + 1)
    dp[0][i] = 0;

  fl(0, n)
    dp[i + 1][0] = dp[i][0] * (1 - probs[i]); 

  fl(0, n){
    for(int j = 0; j < n; j++){
      // cout << i + 1 << " " << j + 1 << " " << probs[i] << endl;
      // cout << dp[i][j] << " " << dp[i - 1][j] << endl;
      dp[i + 1][j + 1] = probs[i] * dp[i][j] + (1 - probs[i]) * dp[i][j + 1];
    }
  }
  
  /*
  fl(0, n + 1){
    for(int j = 0; j <= n; j++)
      cout << dp[i][j] << " ";
    cout << endl;
  }
  */

  long double total_prob = 0;
  fl(n / 2 + 1, n + 1)
    total_prob += dp[n][i];

  cout << setprecision(10) << total_prob << "\n";

}