#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    string s;cin>>s;
    int mod=1e9+7;
    ll dp[4]{};
    dp[0]=1;
    for (char c:s)
        for (int j=3;j>=0;j--) {
            if (c=='?')
                dp[j]=dp[j]*3%mod;
            if (j>0&&(c=='?'||c=="ABC"[j-1]))
                dp[j]=(dp[j]+dp[j-1])%mod;
        }
    cout<<dp[3]<<endl;
    return 0;
}