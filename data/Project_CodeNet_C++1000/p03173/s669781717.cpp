#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define NUM 1000000007
#define MAX 100001
#define INF LLONG_MAX
ll dp[401][401];
ll sum(int i, int j, vector<ll> &v){
    ll val = 0;
    for(int k=i;k<=j;k++){
        val+=v[k];
    }
    return val;
}
ll solve(vector<ll> &v, ll i, ll j){
    if(i>=j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j]=1e18L+5;
    for(int k=i;k<=j;k++){
        dp[i][j]=min(dp[i][j],solve(v,i,k)+solve(v,k+1,j)+sum(i,k,v)+sum(k+1,j,v));
    }
    return dp[i][j];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> v;
    ll tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.pb(tmp);
    }
    for(int i=0;i<401;i++){
        for(int j=0;j<401;j++)
            dp[i][j]=-1;
    }
    cout<<solve(v,0,n-1)<<endl;
    return 0;
}
