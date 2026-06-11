#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;

string get_red_string(int red_set, string S){
  string ans = "";
  for(int i = 0; i < S.size(); i++){
    if(((red_set >> i) & 1) == 1){
      ans.push_back(S[i]);
    }
  }
  return ans;
}

string get_blue_string(int red_set, string S){
  string ans = "";
  for(int i = 0; i < S.size(); i++){
    if(((red_set >> i) & 1) == 0){
      ans.push_back(S[i]);
    }
  }
  return ans;
}

long long dp[18][19];

int main(){
   int N;
   cin >> N;
   string S;
   cin >> S;

   long long ans = 0;
   for(int red_set = 0; red_set < (1 << N); red_set++){
     string red_string = get_red_string(red_set, S.substr(0, N));
     string blue_string = get_blue_string(red_set, S.substr(0, N));

     reverse(blue_string.begin(), blue_string.end());
     reverse(red_string.begin(), red_string.end());
     string target_red_string = blue_string;
     string target_blue_string = red_string;

     for(int i = 0; i < N; i++){
       for(int j = 0; j < i + 2; j++){
         dp[i][j] = 0;
       }
     }

     if(S[N] == target_red_string[0]){
       dp[0][1] = 1;
     }
     if(S[N] == target_blue_string[0]){
       dp[0][0] = 1;
     }
     if(dp[0][1] == 0 && dp[0][0] == 0){
       continue;
     }
     for(int i = 1; i < N; i++){
       for(int j = 0; j < i + 2; j ++){
         if(0 < j && j <= target_red_string.size() && target_red_string[j - 1] == S[N + i]){
           dp[i][j] += dp[i - 1][j - 1];
         }

         if(j <  i + 1 && target_blue_string[i - j] == S[N + i]){
           dp[i][j] += dp[i - 1][j];
         }
       }
     }
     ans += dp[N - 1][target_red_string.size()];
   }
   cout << ans << endl;
   return 0;
}
