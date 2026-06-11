#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define NIL 0
#define INF 1e18
#define vi vector<int> 
#define vvi vector<vector<int>> 
#define vl vector<ll>
#define vvl vector<vector<ll>> 
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define pb push_back
#define F first
#define S second
#define pp pair<int,int> 
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define rpk(i,k,n) for(int i=k;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++) 
#define RPK(i,k,n) for(int i=k;i<=n;i++) 
#define ritr(i,gr) for(auto i=gr.begin();i!=gr.end();i++)

const int M = 1e9+7;

int V, E, i, j, k, u, v, x, y, p, q, r, t, n,m;
vi *g;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cin>>n;
    ll a[n];
    vvl dp(n,vl(n,0)), cost(n,vl(n,INF));
    rep(i,n) cin>>a[i];
    
    rep(i,n) dp[i][i] = a[i], cost[i][i] = 0;
    
    RPK(j,1,n-1) {
        k = j;
        for(int i=0;k<n;i++,k++) {
            x=i;
            dp[i][k] = dp[i][k-1]+dp[k][k];
            while(x<k) {
                ll temp=cost[i][x]+cost[x+1][k]+dp[i][k];
                if(temp<cost[i][k]) cost[i][k] = temp; x++;
            }
        }
    }
    cout<<cost[0][n-1]<<endl;
}
    
    
    