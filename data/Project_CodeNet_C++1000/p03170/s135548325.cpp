#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,k;
    cin >> n >> k;

    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];

    int dp[k+1] = {};
    dp[0] = 0;
    for(int i=1;i<=k;i++)
    {
        dp[i] = 0;
        for(int j=0;j<n;j++)
        {
            if(i-a[j]>=0 && dp[i-a[j]] == 0)
                dp[i] = dp[i]||1;
            else
               dp[i] = dp[i]||0; 
        }
        //cout << i << " " << dp[i] << endl;
    }

    if(dp[k])
        cout << "First\n";
    else
        cout << "Second\n";
}