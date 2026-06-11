#include<bits/stdc++.h>
using namespace std;
#define tpl  tuple<int, int, int>
#define mt   make_tuple
#define LIM  100000


int n, dp[LIM+5][4], vis[LIM+5][4];
vector<tpl> v;

int f(int pos, int k){
    if(pos >= n) return 0;
    if(vis[pos][k]) return dp[pos][k];
    vis[pos][k] = 1;
    int ans;
    if(k == 0) ans = get<0>(v[pos]) + max(f(pos+1, 1), f(pos+1, 2));
    else if(k == 1) ans = get<1>(v[pos]) + max(f(pos+1, 0), f(pos+1, 2));
    else ans = get<2>(v[pos]) + max(f(pos+1, 0), f(pos+1, 1));

    return dp[pos][k] = ans;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        v.push_back(mt(a, b, c));
    }
    int ans = f(0, 0);
    memset(dp, 0, sizeof dp);
    memset(vis, 0, sizeof vis);
    ans = max(ans, f(0, 1));
    memset(dp, 0, sizeof dp);
    memset(vis, 0, sizeof vis);
    ans = max(ans, f(0, 2));

    printf("%d\n", ans);
}
