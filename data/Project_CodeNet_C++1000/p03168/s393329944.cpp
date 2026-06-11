// link here :
#include <bits/stdc++.h>
using namespace std;

#define NAME "rewind"
#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define ms(arr,val) memset(arr,val,sizeof(arr))
#define len length()

const int maxn = 2e5;
double a[3000];
double dp[3000][3000];
int main(){
    //ifstream cin(NAME".inp");
    //ofstream cout(NAME".out");
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++) dp[i][j] = dp[i-1][j] * (1-a[i]) + dp[i-1][j-1]*a[i];
    }
    double ans =0;
    for(int i=n/2+1;i<=n;i++) ans+=dp[n][i];
    cout<<setprecision(12)<<fixed<<ans;
}
