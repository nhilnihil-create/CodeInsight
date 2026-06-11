#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pii pair<int,int>
using namespace std;
const int mod = 1e9+7;
int n;
string s;
int dp[3005][3005],pr[3005];// dp[i][j] _ after i-th position,there are j more left less than i
main() {
    cin >> n >> s;
    s.insert(s.begin(),'<');

    dp[0][0] = 1;
    for (int i  = 0; i < n; i++) {
    int rem = n - i;
    pr[0] = dp[i][0];
    for (int j = 1; j <= n; j++)
        pr[j] = (pr[j-1] + dp[i][j])%mod;
    //for (int j = 0; j <= rem; j++)
     if (s[i] == '<') {
     for (int j = 0; j <= rem; j++)
        (dp[i+1][j] += pr[j])%=mod;
      //  for (int k = j;k <=rem;k++)
       //     (dp[i+1][k] += dp[i][j])%=mod;
        }
        else {
        for (int j = 0; j < rem; j++)
        (dp[i+1][j] += (pr[rem] - pr[j])%mod)%=mod;
            //for (int k = 0; k < j;k++)

            //(dp[i+1][k] += dp[i][j])%=mod;
        }
    }
    cout << (dp[n][0]+mod)%mod;



}
/*
5
<<<<
20
>>>><>>><>><>>><<>>



*/

