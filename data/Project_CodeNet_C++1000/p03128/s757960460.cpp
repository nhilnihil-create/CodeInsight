#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    mp[1] = 2;
    mp[2] = 5;
    mp[3] = 5;
    mp[4] = 4;
    mp[5] = 5;
    mp[6] = 6;
    mp[7] = 3;
    mp[8] = 7;
    mp[9] = 6;


    vector<int> a(m);
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());

    int dp[n+1];
    for(int i = 0; i <= n; i++){
        dp[i] = -1;
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            if(i - mp[a[j]] >= 0){
                dp[i] = max(dp[i], dp[i - mp[a[j]]] + 1);
            }
        }
    }
    // cout << dp[n] << endl;

    string ans = "";
    int idx = 0;
    int mch = n;

    while(mch){
        if(mch - mp[a[idx]] >= 0 && dp[mch - mp[a[idx]]] == dp[mch] - 1){
            mch -= mp[a[idx]];
            // 文字列の追加はこの書き方。
            ans += '0' + a[idx];
        }
        else{
            idx++;
        }
    }
    cout << ans << endl;
    return 0;
}