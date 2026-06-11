#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  ll n,m;
  cin >> n >> m;
  vector<string> use(m);
  for(int i = 0;i < m;i++)cin >> use[i];
  vector<ll> cost = {0,2,5,5,4,5,6,3,7,6};
  vector<string> dp(n + 1);
  for(int i = 0;i < n + 1;i++)dp[i] = "";
  for(int i = 1;i < n + 1;i++){
    for(int j = 0;j < m;j++){
      if(i - cost[stoi(use[j])] == 0){
        //if(i == 6)cout << dp[i].size() << use[j].size() << endl;
        if(dp[i].size() < use[j].size())dp[i] = use[j];
        else if(dp[i].size() == use[j].size())dp[i] = max(dp[i],use[j]);
      }
      else if(i - cost[stoi(use[j])] > 0 && dp[i - cost[stoi(use[j])]] != ""){
        string memo;
        memo = dp[i - cost[stoi(use[j])]];
        memo = use[j] + memo;
        if(dp[i].size() < memo.size())dp[i] = memo;
        else if(dp[i].size() == memo.size())dp[i] = max(dp[i],memo);
        //dp[i] = max(dp[i],memo);
      }
      //if(i == 6)cout << "6の時" << dp[i] << endl;
    }
  }
  //cout << max(to_string(66),to_string(444)) << endl;
  //for(int i = 0;i < n + 1;i++)cout << i << " " << dp[i] << endl;
  cout << dp[n] << endl;
}