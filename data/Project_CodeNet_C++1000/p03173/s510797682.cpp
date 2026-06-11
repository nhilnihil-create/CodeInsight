#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf (1LL<<60)

ll dp[3001][3001];
ll sum[3001][3001];

void preprocess(vector<int> &v, int n){

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            sum[i][j] = v[j] + ((j == i) ? 0 : sum[i][j-1]);
        }
    }
}

ll solve(vector<int> &v, int i, int j){

    if(i==j)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    ll mincost = inf;

    for(int k=i;k<j;k++){
        mincost = min(mincost,sum[i][j] + solve(v,i,k) + solve(v,k+1,j));
    }

    return dp[i][j] = mincost;
}

int main() {
    
    int n;
    cin>>n;

    vector<int> v(n+1);
    memset(dp,-1,sizeof dp);

    for(int i=1;i<=n;i++)
        cin>>v[i];

    preprocess(v,n);
    cout<<solve(v,1,n);

    return 0;
}
