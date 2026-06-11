#include <bits/stdc++.h>
using namespace std;
const int maxn=(1<<26)+100;
const int maxm=2e5+100;
int g[maxn];
char s[maxm];
int dp[maxm];
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin >> (s+1);

    fill(g,g+maxn,1001000);
    g[0]=0;
    dp[0]=1;
    int cd=0,len=strlen(s+1);
    for(int i=1;i<=len;++i) {
        dp[i]=1001000;
        int tmp=s[i]-'a';
        cd^=(1<<tmp);
        for(int j=0;j<26;++j) {
            int p=(1<<j)^cd;
            dp[i]=min(g[p]+1,dp[i]);
        }
        dp[i]=min(g[cd]+1,dp[i]);
        g[cd]=min(g[cd],dp[i]);

    }

    cout << dp[len] << endl;
    return 0;
}
