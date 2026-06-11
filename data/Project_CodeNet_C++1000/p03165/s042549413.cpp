#include <bits/stdc++.h>
#define nl "\n"
#define pb push_back
#define E esit(0)
#define all(v) v.begin(),v.end()
using namespace std;
using ll=long long;
const int N=1e5+5;
const int INF=1e9+7;
int dp[3001][3001];
string s,s1,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s>>s1;
    ll n=s.size(),m=s1.size();
    s=" "+s;
    s1=" "+s1;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (s[i]==s1[j]) {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    while (n!=0 && m!=0) {
        if (s[n]==s1[m]) {
            ans+=s[n];
            n--;
            m--;
        }
        else {
            if (dp[n-1][m]>dp[n][m-1]) n--;
            else m--;
        }
    }
    for (int i=ans.size()-1;i>=0;i--) {
        cout<<ans[i];
    }
}