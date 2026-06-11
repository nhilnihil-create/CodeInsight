#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<char,int>;
using PL = pair<ll,ll>;
const vector<P> in = {{'1', 2}, {'2', 5}, {'3', 5}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 3}, {'8', 7}, {'9', 6}};
const int INF = 1e9;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<P> use(m);
    for(int i = 0; i < m; i++) {
        int t; cin >> t; t--;
        use[i] = in[t];
    }   
    sort(use.begin(), use.end(), greater<P>());

    vector<int> dp(n + 1, -INF); //マッチをi本使って作れる最大の桁数
    dp[0] = 0;
    
    for(int i = 0; i < n; i++) {
        for(auto j : use) {
         	if(i + j.second > n)continue;
            dp[i + j.second] = max(dp[i + j.second], dp[i] + 1);
        }
    }
    //cerr << dp[n] << endl;

    //上の桁から見ていって
    string ans = "";
    int cur = n;

    for(int i = 0; i < dp[n]; i++) {

        for(auto j : use) {
            if(cur - j.second < 0)continue; //使えない
            if(dp[cur - j.second] == dp[cur] - 1) {
                ans.push_back(j.first);
                cur -= j.second;
                break;
            }
        }
    }
    if((int)ans.size() != dp[n]) {
        return 1;
    }
    cout << ans << endl;
}