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

int V, E, i, j, k, u, v, x, y, p, q, r, t, n;
vi *g;
vb sn;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    int a[n];
    rep(i,n) cin>>a[i];
    
    bool dp[k+1];
    dp[0] = false;
    REP(i,k) {
        bool ans = false;
        rep(j,n) {
            if(a[j]<=i) if(dp[i-a[j]]==false) ans=true;
        }
        dp[i] = ans;
    }
    if(dp[k]) cout<<"First\n";
    else cout<<"Second\n";
}
    
    
    