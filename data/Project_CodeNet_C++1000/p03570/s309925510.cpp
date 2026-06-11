#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define INF 1e9

int main(void){
    string s;
    cin>>s;
    int N = s.size();
    vector<int> dp(1<<26,INF);
    dp[0] = 0;
    int bit = 0;
    rep(i,N){
        bit ^= (1<<(s[i]-'a'));
        rep(j,26) {
            dp[bit] = min(dp[bit], dp[bit^(1<<j)]+1);            
        }
    }
    cout<<max(1,dp[bit])<<endl;
}
