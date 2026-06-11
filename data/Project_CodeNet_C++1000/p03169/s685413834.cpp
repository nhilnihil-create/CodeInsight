#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> cnt(4);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        cnt[x]++;
    }
   double dp[n+1][n+1][n+1];
    memset(dp,0,sizeof dp);
    for(int three=0;three<=n;three++)
    {
        for(int two=0;two<=n;two++)
        {
            for(int one=0;one<=n;one++)
            {
                double c=one+two+three;
                double z = n-c;
                if(c>n||c==0)
                continue;
                double val = 1.0;
                val+=(1.0)*one/n*dp[one-1][two][three];
                val+=(1.0)*two/n*dp[one+1][two-1][three];
                val+=(1.0)*three/n*dp[one][two+1][three-1];
                val = 1.0*val/(1.0-1.0*z/n);
                dp[one][two][three] = val;
            }
        }
    }
    cout<<setprecision(10)<<fixed;
    cout<<dp[cnt[1]][cnt[2]][cnt[3]];
}
