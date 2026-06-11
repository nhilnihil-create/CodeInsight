#include <bits/stdc++.h>
#include <math.h>


    using namespace std;
    typedef long long ll;
    # define M_PI  3.14159265358979323846
    const int MOD=1e9+7;

    void solve(){
        int n,k;
        cin>>n>>k;
        vector<int>a(n+1);
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int dp[n+1][k+1];
        dp[0][0]=1;
        for(int i=1;i<=k;i++)
            dp[0][i]=0;
        for(int i=1;i<=n;i++){
            vector<int>sum(k+1);
            sum[0]=dp[i-1][0];
            for(int j=1;j<=k;j++)
                sum[j]=(sum[j-1]+dp[i-1][j])%MOD;
            for(int j=0;j<=k;j++){
                if(j<=a[i])
                    dp[i][j]=sum[j];
                else{
                    int non_existing=j-a[i]-1;
                    dp[i][j]=(sum[j]-sum[non_existing]+MOD)%MOD;
                }
            }
            sum.clear();
        }
//        for(int i=0;i<=n;i++){
//            for(int j=0;j<=k;j++)
//                cout<<dp[i][j]<<" ";
//            cout<<"\n";
//        }
        cout<<dp[n][k];
    }

    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout<<setprecision(10);
        int t=1;
//        cin>>t;
        for(int i=1;i<=t;i++){
            solve();
        }
        return 0;
    }
