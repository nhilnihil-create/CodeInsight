#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;
int A[9];
int match_map[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
bool used_match_no[10];
int dp[10][10001];
vector <int> use_matches;
int main(){
    int N;
    int M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
      cin >> A[i];
    }
    sort(A, A + M);
    
    for(int i = M - 1; i >= 0; i--){
      if(!used_match_no[match_map[A[i]]]){
        use_matches.push_back(A[i]);
        used_match_no[match_map[A[i]]] = true;
      }
    }
    reverse(use_matches.begin(), use_matches.end());
    
    for(int i = 0; i < use_matches.size(); i++){
      for(int j = 0; j <= N; j++){
        dp[i][j] = -1;
      }
    }

    for(int i = 0; i <= N; i++){
      if(i % match_map[use_matches[0]] == 0){
        dp[0][i] = i / match_map[use_matches[0]];
      }
    }

    for(int i = 1; i < use_matches.size(); i++){
      dp[i][0] = 0;
      for(int j = 0; j <= N; j++){
        int cur_match_no = match_map[use_matches[i]];
        if(j < cur_match_no || dp[i][j - cur_match_no] < 0){
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - cur_match_no] + 1);
        }
      }
    }

    string ans = "";
    int cur_total_match_no = N;
    for(int i = use_matches.size() - 1; i >= 1; i--){
      while(cur_total_match_no - match_map[use_matches[i]] >= 0 
        && dp[i][cur_total_match_no - match_map[use_matches[i]]] >= 0 
        && dp[i][cur_total_match_no - match_map[use_matches[i]]] + 1 >= dp[i - 1][cur_total_match_no]){
          cur_total_match_no -= match_map[use_matches[i]];
          ans.push_back('0' + use_matches[i]);
      }
    }
    for(int i = 0; i < dp[0][cur_total_match_no]; i++){
      ans.push_back('0' + use_matches[0]);
    }
    cout << ans << endl;
    return 0;
}
