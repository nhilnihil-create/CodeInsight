#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    rep(i, s1.size() + 1)dp[i][0] = 0;
    rep(i, s2.size() + 1)dp[0][i] = 0;
    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++){
            if(s1[i - 1] == s2[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // rep(i, s1.size() + 1){
    //     rep(j, s2.size() + 1)cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    int s1now = s1.size();
    int s2now = s2.size();
    vector<char> ans(dp[s1.size()][s2.size()]);
    int index = ans.size() - 1;
    while(dp[s1now][s2now] != 0){
        if(dp[s1now][s2now] != dp[s1now - 1][s2now] && dp[s1now][s2now] != dp[s1now][s2now - 1]){
            ans[index] = s1[s1now - 1];
            s1now--;
            s2now--;
            index--;
        }else if(dp[s1now][s2now] == dp[s1now - 1][s2now]){
            s1now--;
        }else s2now--;
    }
    rep(i, ans.size())cout << ans[i];
    cout << endl;
}