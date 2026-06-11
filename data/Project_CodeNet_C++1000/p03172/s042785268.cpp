// link here :
#include <bits/stdc++.h>
using namespace std;

#define NAME "rewind"
#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define ms(arr,val) memset(arr,val,sizeof(arr))
#define len length()

const int maxn = 1e5;
const int mod = 1e9+7;
int a[101];
ll dp[101][maxn+1];
ll tmp[maxn+1];
int main(){
    //ifstream cin(NAME".inp");
    //ofstream cout(NAME".out");
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];

    dp[0][k]=1;

    for(int i=1;i<=n;i++){

        for(int j=0;j<=k;j++){
            int L = max(0, j-a[i] );
            tmp[L] = ( tmp[ L ] + dp[i-1][j] )%mod;
            if (j+1<=k) tmp[j+1] = ( tmp[j+1] - dp[i-1][j]+ mod)%mod;
        }

        ll presum = 0;
        for(int j=0;j<=k;j++){
            presum = (presum + tmp[j])%mod;
            dp[i][j] = presum;
        }
        //for(int j=0;j<=k;j++) cout<<dp[i][j]<<" ";
        //cout<<endl;
        ms(tmp,0);
    }
    cout<<dp[n][0];
}
