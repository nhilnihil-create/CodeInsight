#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define len_max 4000
string x, y;
long long dp[len_max+1][len_max+1];

long long lcs(){
    long long m = x.size();
    long long n = y.size();

    x = ' ' + x;
    y = ' ' + y;

    for(long long i = 0; i <= n; i++) dp[i][0] = 0;
    for(long long i = 0; i <= m; i++) dp[0][i] = 0;

    for(long long i = 1; i <= n; i++){
        for(long long j = 1; j <= m; j++){
            if(y[i] == x[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
}

int main(){
    cin >> x >> y;

    long long len = lcs();

    long long i = y.size();
    long long j = x.size();
    i--;
    j--;
    len--;
    //printf("len %lld\n", len);
    string ans;

    while(len >= 0){
        if(x[j] == y[i]){
            //ans[len] = y[i];
            ans.push_back(y[i]);
            i--;
            j--;
            len--;
        }
        else if(dp[i][j] == dp[i-1][j]) i--;
        else j--;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}