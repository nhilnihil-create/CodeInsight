#include <bits/stdc++.h>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0);
const int M = 1e9+7;
using namespace std;
int n;
string str;
ll dp[3005][3005];

int main(){
    AC
    cin>>n;
    cin>>str;
    dp[1][1] = 1;
    for(int i=2; i<=n; i++){
        if(str[i-2]=='>'){
            for(int s=i; s>=1; s--)
                dp[i][s] = (dp[i][s+1]+dp[i-1][s])%M;
        }
        else{
            for(int s=1; s<=i; s++)
                dp[i][s] = (dp[i][s-1] + dp[i-1][s-1])%M;
        }
    }

    ll ans = 0;
    for(int i=1; i<=n; i++)
        ans = (ans+dp[n][i])%M;
    cout<<ans<<endl;
}