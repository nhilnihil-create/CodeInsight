#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> b = {0,2,5,5,4,5,6,3,7,6};
    int n,m; cin>>n>>m;
    vector<int> a(m);rep(i,m)cin>>a[i];
    sort(a.rbegin(),a.rend());
    vector<ll> dp(n+1,-INF);
    dp[0]=0;
    for(int i=1; i<=n; i++){
        ll M = -INF;
        for(int j:a){
            if(b[j]<=i)M=max(M,dp[i-b[j]]+1);
        }
        dp[i]=M;
    }
    

    for(int j:a){
        while(n>=b[j]&&dp[n]==dp[n-b[j]]+1){cout<<j;n-=b[j];}
    }

    return 0;
}