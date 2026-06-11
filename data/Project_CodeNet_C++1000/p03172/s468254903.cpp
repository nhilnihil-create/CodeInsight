#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define NUM 1000000007
#define MAX 100001
#define INF LLONG_MAX
ll dp[101][MAX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k,tmp;
    cin>>n>>k;
    vector<ll> v;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.pb(tmp);
    }
    //memset(dp,0,sizeof(dp));
    for(int i=0;i<=v[0];i++){
        dp[0][i]=1;
    }
    for(int i=1;i<n;i++){
        vector<ll> prf(k+1);
        prf[0]=dp[i-1][0];
        for(int j=1;j<=k;j++){
            prf[j]=(prf[j-1]+dp[i-1][j])%NUM;
        }
        for(int j=0;j<=k;j++){
            if(j>v[i]){
                dp[i][j]=(prf[j]+NUM-prf[j-v[i]-1])%NUM;
            }
            else
                dp[i][j]=prf[j];
        }
    }
    cout<<dp[n-1][k]<<endl;
    return 0;
}
