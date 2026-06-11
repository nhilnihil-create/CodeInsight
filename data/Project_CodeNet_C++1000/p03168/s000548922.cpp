#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define F first
#define S second
#define mod 1000000007

int main()
{
    int n,i,j,k,l,p;
    cin >> n;
    vector<double> prob(n);
    vector< vector< double > > dp(n + 1, vector<double>(n + 1, 0));

    dp[0][0] = 1;
    for(auto &i : prob)cin >> i;

    for(j = 0; j <= n; j++){
        for(i = 0; i < n; i++){
            dp[i + 1][j] = dp[i][j] * (1 - prob[i]);
            if(j)
                dp[i + 1][j] += dp[i][j - 1] * prob[i];
        }
    }

    double ans = 0;
    for(i = n / 2 + 1; i <= n; i++){
        ans += dp[n][i];
    }
    cout<<setprecision((20));
    cout << ans << endl;
}
