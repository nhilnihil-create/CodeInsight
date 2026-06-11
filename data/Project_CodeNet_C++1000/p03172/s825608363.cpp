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
    cin>>n>>k;
    ll a[n+1];
    REP(i,n) cin>>a[i];
    vvl dp(n+1, vl(k+1, 0));
    REP(i,n) dp[i][0] = 1;
    REP(i,k) if(i<=a[1]) dp[1][i] = 1;
    ll psum[k+1];
    RPK(i,2,n) {
        psum[0] =1;
        REP(j,k) psum[j]= (psum[j-1]+dp[i-1][j]+M)%M;
        REP(j,k) {
            if(j>a[i]) 
                dp[i][j] += (psum[j]-psum[j-a[i]-1]+M)%M;
            else dp[i][j] += psum[j];
        }
    }   
    cout<<dp[n][k]<<endl;
}
    