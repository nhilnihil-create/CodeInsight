#include<bits/stdc++.h>
using namespace std;
#define LL  long long
#define LIM 400


LL dp[LIM+5][LIM+5], ara[LIM+5], csum[LIM+5];
bool vis[LIM+5][LIM+5];
int n;

LL f(int lft, int rht){
    if(lft == rht) return 0;
    if(lft > rht) return 1e15;
    if(vis[lft][rht]) return dp[lft][rht];
    vis[lft][rht] = 1;
    LL ans = 1e15;
    for(int k = lft; k <  rht; k++){
        LL cur = f(lft, k) + f(k+1, rht) + (csum[rht] - csum[lft-1]);
        ans = min(ans, cur);
    }
    return dp[lft][rht] = ans;
}

int main(){
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>ara[i];
    for(int i = 1; i <= n; i++) csum[i] = csum[i-1] + ara[i];
    LL res = f(1, n);

    cout<<res<<'\n';
}


