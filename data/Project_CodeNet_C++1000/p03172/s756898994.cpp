#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<ll,pair<ll,char>>
#define sorted(a_1) sort(a_1.begin(),a_1.end())
#define rsorted(a_1) sort(a_1.rbegin(),a_1.rend())
#define t1(a_1) cout<<a_1<<endl;
#define t2(a_1) for(auto it_test : a_1) cout<<it_test<<" ";
#define MOD 1000000007

ll dp[101][100001];
ll topDown(vector<ll>&arr, ll index, ll k){
    if(k==0) return 1LL;
    if(index<0) return 0LL;
    if(dp[index][k]>=0) return dp[index][k];
    ll ways = 0;    
    for(ll i=min(arr[index],k);i>=0;i--){
        ways+=topDown(arr,index-1, k-i)%MOD;
        ways%=MOD;
    }
    dp[index][k] = ways;
    return ways;
}
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll>arr(n),cnt(n+1,0);
    for(auto &i : arr) cin>>i;
    memset(dp,0,sizeof(dp));
    // ll ans = topDown(arr,n-1,k);
    // t1(ans)
    dp[0][0] = 1;
    for(int i=1;i<=k;i++) dp[0][i] += dp[0][i-1];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(j-arr[i-1]>0){
                dp[i][j] = ((dp[i-1][j]%MOD - dp[i-1][j-arr[i-1]-1]%MOD) + MOD)%MOD;
            }
            else
                dp[i][j] = dp[i-1][j]%MOD;
        }
        for(int j=1;j<=k;j++) {
            dp[i][j]+=dp[i][j-1];
            dp[i][j]%=MOD;
        }
    }

    t1((dp[n][k] - dp[n][k-1]+MOD)%MOD);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    while(t--){
        solve();
    }

return 0;
}