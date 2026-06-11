#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define F first
#define S second
//cout<<fixed<<setprecision(11);
const string nl="\n";
const ll MOD=1e9+7;
const int ARR_MAX = 3003;
const ll VAL_MAX = 1e5+1;
const ll INF=1e14;

ll dp[ARR_MAX],cum_dp[ARR_MAX+2];
//dp[j] = number of permutations with j as the last element of the sequence.
//dp[i][j] = number of ways to get prefix of size i such that last number is j.

void solve(){
    int n;cin>>n;
    string s;
    cin>>s;
    memset(dp,0,sizeof(dp));    
    dp[0]=1;
    for(int i=0;i<n-1;i++){
        //length of string processed so far = i+1;
        //numbers used so far are 0,...,i.
        cum_dp[0]=0;
        for(int j=0;j<=i;j++){
            cum_dp[j+1]=(cum_dp[j] + dp[j])%MOD;
        }
        for(int j=0;j<=i+1;j++){
            if(s[i]=='<'){
                dp[j]=cum_dp[j];
            }
            else{
                dp[j]=(cum_dp[i+1]-cum_dp[j]+MOD)%MOD;
            }
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=dp[i];
        ans%=MOD;
    }
    cout<<ans<<nl;
}

int main(){
    fastio();
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}