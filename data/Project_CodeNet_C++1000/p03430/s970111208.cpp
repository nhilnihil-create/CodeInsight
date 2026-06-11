#include<bits/stdc++.h>
#define ll int
#define f first
#define s second
#define pb push_back
using namespace std;
ll dp[301][301][301],k;
string s;
inline ll solve(ll x,ll y,ll p){
    if(dp[x][y][p])return dp[x][y][p];
    if(x == y){
        dp[x][y][p] = 1;
        return dp[x][y][p];
    }
    if(x + 1 == y){
        if(s[x] == s[y] || p)dp[x][y][p] = 2;
        else dp[x][y][p] = 1;
        return dp[x][y][p];
    }
    if(p == 0){
        if(s[x] == s[y]){
            dp[x][y][p] = solve(x + 1 ,y - 1, p) + 2;
            return dp[x][y][p];
        }
        ll t = solve(x , y - 1 , p);
        ll r = solve(x + 1 , y , p);
        dp[x][y][p] = max(t,r);
        return dp[x][y][p];
    }
    if(s[x] == s[y]){
        dp[x][y][p] = solve(x + 1, y - 1 , p) + 2;
        return dp[x][y][p];
    }
    dp[x][y][p] = solve(x + 1 , y - 1 , p);
    ll t = solve(x , y - 1 , p);
    ll r = solve(x + 1 , y , p);
    ll q = solve(x + 1 , y - 1, p - 1) + 2;
    q = max(q , max(t , r));
    if(dp[x][y][p] < q)dp[x][y][p] = q;
    return dp[x][y][p];
}
int main(){
    ios::sync_with_stdio(false);
    cin >> s >> k;
    
    cout << solve(0 , (int)s.size() - 1 , k);
    
    
    
    return 0;
}
