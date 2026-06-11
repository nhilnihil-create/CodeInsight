#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,a[105];
long long int ans[105][100005];
int main(){
    int k;
    cin >> n >> k;
    memset(ans, 0, sizeof(ans));
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=0; i<=n; i++){
        ans[i][0] = 1;
    }
    for(int i=0; i<=k;i++)
        ans[0][i] = 1;
    

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(j-a[i]>0)
                ans[i][j] = ((ans[i-1][j] - ans[i-1][j-a[i]-1])%mod + mod)%mod;
            else
                ans[i][j] = (ans[i-1][j])%mod;
            ans[i][j] = (ans[i][j] + ans[i][j-1])%mod;
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0; j<=k;j++){
    //         cout<<ans[i][j] << " ";
    //     }
    //     cout<<"\n";
    // }
    if(k>0)
        cout << ((ans[n][k]-ans[n][k-1])%mod+mod)%mod;
    else
        cout << ans[n][k];
    return 0;
}