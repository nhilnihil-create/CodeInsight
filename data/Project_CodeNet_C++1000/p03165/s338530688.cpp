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
    int cnt = dp[S][T];
    vector<char> ans(cnt);
    int si = S, sj = T;
    int flag = 0;
    while(cnt > 0){
        if(s[si - 1] == t[sj - 1]){
            ans[cnt - 1] = s[si - 1];
            si--;
            sj--;
            cnt--;
        }
        else if(dp[si][sj] == dp[si - 1][sj]){
            si--;
        }
        else sj--;
    }
    for(int i = 0; i < dp[S][T];i++){
        cout << ans[i];
    }
    cout << endl;
}