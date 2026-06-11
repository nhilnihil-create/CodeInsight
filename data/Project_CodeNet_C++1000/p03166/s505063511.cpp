#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define rep(i, a) for (int i = 0; i < (a); i++)
#define repd(i, a) for (int i = (a)-1; i >= 0; i--)
#define reps(i, a, j) for (int i = (j); i < (a); i++)
#define deb(x) cout << #x << " " << x << endl;
#define debs(x) cout << #x << " " << x << " ";
#define deba(x) for (auto _i:x) cout << _i << " "; cout << endl;
#define ms(a) memset(a,0,sizeof(a));
#define mp make_pair
#define eb emplace_back
#define FastOpen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define pii pair < int , int >
#define all(a) a.begin(),a.end() 
//int power(int x,int p){if(p==0)return 1;if(p==1)return x;if(p%2)return x*power(x,p-1);int y=power(x,p/2);return y*y;}
/*
*/

void solve() {
    int n,m,res = 0; cin >> n >> m;
    vector < int > g[n],in_degree(n,0),dp(n,0);
    rep(i,m) {
        int x,y; cin >> x >> y;
        x--;
        y--;
        g[x].eb(y);
        in_degree[y] ++;
    }
    deque < int > q;
    rep(i,n) if (in_degree[i] == 0) q.push_back(i);
    while (!q.empty()) {
        int x = q.front();
        q.pop_front();
        for (auto v:g[x]) {
            in_degree[v]--;
            dp[v] = max(dp[v],dp[x]+1);
            if (in_degree[v] == 0) q.push_back(v);
        }
    }
    rep(i,n) res = max(res,dp[i]);
    cout << res << endl;   
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    FastOpen
    int t; t=1;
    while (t--) solve();
}



