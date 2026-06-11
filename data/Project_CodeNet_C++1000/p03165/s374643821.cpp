#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string s, t;
    cin >> s >> t;
    int S = (int)s.size();
    int T = (int)t.size();
    int INF = 1e9;
    vector<vector<int>> dp(S + 1, vector<int>(T + 1, 0));
    for(int i = 1; i < S + 1; i++){
        for(int j = 1; j < T + 1; j++){
            if(s[i - 1] == t[j - 1]){
                int temp = dp[i][j];
                dp[i][j] = max(dp[i - 1][j - 1] + 1, max(dp[i - 1][j], dp[i][j - 1]));
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string ans;
    int cnt = dp[S][T];
    int si = S, sj = T;
    int flag = 0;
    while(cnt != 0){
        if(dp[si][sj] > dp[si][sj - 1]) {
            ans += t[sj - 1];
            cnt--;
            sj--;
            flag = 0;
            continue;
        }
        if(flag == 0){
            if(dp[si][sj] > dp[si - 1][sj]) {
                flag = 1;
                continue;
            }
            si--;
        }
        if(flag == 1){
            sj--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}