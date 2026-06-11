#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int dp[201010];
int main(){
    int n;
    cin>>n;
    int P[n];
    rep(i,n) cin>>P[i];

    int ans=0;
    rep(i,n){
        int p=P[i];
        dp[p]=dp[p-1]+1;
        ans=max(ans,dp[p]);
    }

    cout<<n-ans<<endl;
}


 