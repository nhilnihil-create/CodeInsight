#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
const int W = 1e4 + 4;
int w[N] , s[N] , v[N];
long long dp[N][W];
int idx[N];
int n;

long long solve(int i , int weight){
    if(weight >= W)return 0;
    if(i == n)return 0;
    long long &ret = dp[i][weight];
    if(~ret)return ret;
    ret = solve(i+1,weight);
    if(weight <= s[idx[i]])
        ret = max(ret , solve(i+1,weight+w[idx[i]]) + v[idx[i]]);
    return ret;
}


int main(){

    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d%d%d",&w[i],&s[i],&v[i]);
        idx[i] = i;
    }

    sort(idx,idx+n,[&](int i , int j){
            return s[i] + w[i] < s[j] + w[j];
        });

    memset(dp,-1,sizeof dp);
    printf("%lld\n",solve(0,0));

    return 0;
}
