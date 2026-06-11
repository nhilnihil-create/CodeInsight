#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int, int >
#define F first
#define S second
#define int  long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
using namespace std;
/// age ye mosh dp ro baze dashti dp tedad baz shodeye baste nashode yadet nare !!
/// joooob zadam
const int N=5003;
ll dp[N][N];
ll last[N][N];
ll b[N][N];
ll a[N];
int32_t main(){
    ll n,a1,b1;
    cin >> n >> a1 >> b1 ;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<N;j++){
            if (a[i]<j){
                last[i][j]=i;
            }
            else{
                last[i][j]=last[i-1][j];
            }
            if (a[i]>j){
                b[i][j]=b[i-1][j]+1;
            }
            else{
                b[i][j]=b[i-1][j];
            }
        }
    }
    a[0]=0;
    memset(dp,69,sizeof dp);
    for (int i=0;i<N;i++){
        dp[0][i]=0;
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<N;j++){
            ll l=last[i][j];
          //  for (int k=i;k>0;k--){
            //    if (a[k]<j){
                 //   l=k;
                   // break;
           //     }
           // }
            if (!l){
                dp[i][j]=0;
                continue;
            }
            dp[i][j]=dp[l-1][j]+b1;
            //ll z=0;
            ll z=b[l][a[l]]-b[l][j-1];
          //  for (int k=1;k<l;k++){
            //    if (a[k]>a[l] && a[k]<j){
                    //z++;
              //  }
          //  }
            dp[i][j]=min(dp[i][j],dp[l-1][a[l]]+z*a1);
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << dp[n][N-1];
}
