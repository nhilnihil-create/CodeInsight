// link here :
#include <bits/stdc++.h>
using namespace std;

#define NAME "I - Coins"
#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define ms(arr,val) memset(arr,val,sizeof(arr))
#define len length()

const int maxn = 2999;
double a[maxn+1];
double dp[maxn+1][maxn+1];
int main(){
    //ifstream cin(NAME".inp");
    //ofstream cout(NAME".out");
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i];
    ms(dp,0);
    dp[0][0]=1;
    for(int i = 1;i<=n;i++)
        for(int j=0;j<=i;j++){
            dp[i][j] = dp[i-1][j]*(1.0-a[i]);
            if (j>0) dp[i][j]+= dp[i-1][j-1]*a[i];
        }

    double ans = 0;
    for(int i=n/2+1;i<=n;i++) ans+= dp[n][i];
    cout<<setprecision(10)<<fixed<<ans;
}

