#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; cin >> S;
    int n=S.size();
    vector<int> cnt(n+1,0);
    for (int i=0;i<n;++i) cnt[i+1]=cnt[i]^(1<<(S[i]-'a'));
    vector<int> dp(n+1,INF);
    map<int,int> m;
    dp[0]=0; m[0]=0;
    for (int i=0;i<n;++i){
        if (m.count(cnt[i+1])) dp[i+1]=min(dp[i+1],m[cnt[i+1]]+1);
        for (int j=0;j<26;++j){
            int mask=cnt[i+1]^(1<<j);
            if (m.count(mask)) dp[i+1]=min(dp[i+1],m[mask]+1);
        }
        if (!m.count(cnt[i+1])) m[cnt[i+1]]=dp[i+1];
        else m[cnt[i+1]]=min(m[cnt[i+1]],dp[i+1]);
    }
    cout << dp[n] << '\n';
}