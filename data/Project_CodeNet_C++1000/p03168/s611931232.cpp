#include <bits/stdc++.h>

#define IO  ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define endl '\n'
#define f first
#define s second
#define ll long long
#define mod 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int main() {
    IO
    int n;
    cin>>n;
    double head[n+5],tail[n+5],dp[n+5][n+5]={},ans=0.0;
    for(int i=0;i<n;i++){
        cin>>head[i];
        tail[i]=1.0-head[i];
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(j==0){
                dp[i][j]=tail[i-1]*dp[i-1][j];
            }
            else{
                dp[i][j]=head[i-1]*dp[i-1][j-1]+tail[i-1]*dp[i-1][j];
            }
        }
    }
    for(int i=n;i>n/2;i--){
        ans+=dp[n][i];
    }
    cout<<fixed<<setprecision(10)<<ans;
    return 0;
}
