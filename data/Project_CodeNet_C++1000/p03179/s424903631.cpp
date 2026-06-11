#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 1000000007

ll permutation(string &s, int n){

    ll dp[n+1][n+1], prefix[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    memset(prefix, 0, sizeof(prefix));

    for(int i=1; i<=n; i++){
        dp[1][i] = 0;
        prefix[1][i] = 1;
    }
    dp[1][1] = 1;


    for(int i=2; i<=n; i++){
        if(s[i-2] == '<'){
            for(int j=1; j<=i; j++){
//                ll sum = 0;
//                for(int k=1; k<j; k++)
//                    sum = (sum + dp[i-1][k])%M;
                ll sum = (prefix[i-1][j-1] - prefix[i-1][0] + M)%M;
                dp[i][j] = sum;
                prefix[i][j] = (prefix[i][j-1] + sum)%M;
            }
            for(int j=i+1; j<=n; j++)
                prefix[i][j] = prefix[i][j-1];
        }
        else{
            for(int j=1; j<=i; j++){
//                ll sum = 0;
//                for(int k=j; k<=n; k++)
//                    sum = (sum + dp[i-1][k])%M;
//                dp[i][j] = sum;
                ll sum = (prefix[i-1][n] - prefix[i-1][j-1] + M)%M;
                dp[i][j] = sum;
                prefix[i][j] = (prefix[i][j-1] + sum)%M;
            }
            for(int j=i+1; j<=n; j++)
                prefix[i][j] = prefix[i][j-1];
        }
    }
    ll ans = 0;
    for(int i=1; i<=n; i++)
        ans = (ans + dp[n][i])%M;
    return ans;
}

int main()
{
 int n;
 cin>>n;
 string s;
 cin>>s;
 ll ans = permutation(s, n);
 cout<<ans;
 return 0;
}

