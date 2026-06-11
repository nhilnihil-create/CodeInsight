#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "  = " << x << endl
typedef long long int ll;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

#define dbg2(x, y)                                                       \
    {                                                                    \
        cout << #x << ": " << (x) << " , " << #y << ": " << (y) << endl; \
    }
#define fo(i, n) for (int i = 0; i < n; i++)
#define fok(i, k, n) for (int i = k; i < n; i++)
#define foA(i, A) for (auto i : A)
const int mxN=403;
const int modd=1e9+7;
const ll mx=1e15;
ll a[mxN];
int n;


int main(){
    cin>>n;
    fo(i, n)cin>>a[i];
    ll dp[n][n];
    ll psum[n];
    psum[0]=a[0];
    for(int i=1;i<n;i++)psum[i]=psum[i-1]+a[i];
    for(int ws=1; ws<=n;ws++){
        for(int i=0;i<n-ws+1;i++){
            int j=i+ws-1;
            if(i==j){dp[i][j]=0; continue;}
            dp[i][j]=mx;
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]);
            }
            dp[i][j]+=(psum[j]-(i==0 ? 0: psum[i-1]));
        }
    }
    ll ans=dp[0][n-1];
    cout<<ans;
}