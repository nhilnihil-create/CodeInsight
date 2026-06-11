#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long LL;
const int N = 1e5+100, M = 2*N,mod = 1e9+7;

LL dp[N][2];  //0是黑色， 1是白色
int n;
int h[N],e[M],ne[M],idx;

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a],h[a] = idx++;
}

void dfs(int u,int fa = 0){   //，fa是u的父节点
    dp[u][0] = dp[u][1] = 1;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(fa == j) continue;  //防止绕圈
        dfs(j,u);
        dp[u][0] = (dp[u][0] * dp[j][1])%mod;
        dp[u][1] = (dp[u][1] * (dp[j][0] + dp[j][1]))%mod;
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i = 0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    
    dfs(1);
    LL ans = (dp[1][0] + dp[1][1])%mod;
    
    cout<<ans;
    return 0;
}