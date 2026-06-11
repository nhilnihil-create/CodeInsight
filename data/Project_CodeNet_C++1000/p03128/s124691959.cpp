#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long
using namespace std;
int main()
{
    vector<int> dp(10030,-1);
    int n, m;
    cin >> n >> m;
    vector<int> a(m),use={0,2,5,5,4,5,6,3,7,6};
    rep(i,m){
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    for(auto e:a){
        dp[use[e]]=1;
    }
    dp[0] = 0;
    rep(i,n+1){
        if(dp[i]==-1)
            continue;
        for(auto e:a){
            dp[i + use[e]] = max(dp[i] + 1, dp[i + use[e]]);
        }
    }
    string ans;
    int remain = dp[n];
    int match = n;
    while(match > 0){
        for(auto e: a){
            if(match<use[e])
                continue;
            if(dp[match-use[e]]==remain-1){
                match -= use[e];
                remain--;
                ans += char('0'+e);
                break;
            }
        }        
    }
    cout << ans << endl;
}
