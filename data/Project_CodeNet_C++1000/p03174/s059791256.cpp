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
    
    ll amsk = 1<<n, msk=0;
    bool pr[n][n];
    rep(i,n) rep(j,n) cin>>pr[i][j];
    vl dp(amsk, 0);
    dp[0]=1;
    
    rep(msk,amsk) {
        bitset<22> b1(msk); 
        int nbits = b1.count();
        rep(j,n) {
            if((pr[nbits][j]==true&&(msk&(1<<j))==0)) {
                dp[msk|(1<<j)] = (dp[msk|(1<<j)]+ dp[msk]+M)%M;
            }
        }
    }
    cout<<dp[amsk-1]<<endl;
}
    
    
    