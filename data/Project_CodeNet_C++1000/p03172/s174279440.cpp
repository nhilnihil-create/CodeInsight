#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define snd second
#define ALL(s) s.begin(),s.end()
#define fill(a,c) memset(&a, c, sizeof(a))
#define fore(i,x,y) for(ll i=x;i<y;i++)
#define SZ(x) ((int)(x).size())
#define PI acos(-1)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
using namespace std;

const int MAXN = 1e5+10;
ll dp[110][MAXN];
const ll mod = 1e9+7;

int main() {FIN;
    int n,k; cin>>n>>k;
    vector<int> c(n);
    fore(i,0,n) cin>>c[i];
    memset(dp,0,sizeof(dp));
    fore(i,0,n+1) dp[i][0] = 1;
    fore(i,0,k+1) dp[0][i] = 1;
    fore(i,1,n+1){
        fore(j,1,k+1){
            ll a = (j-c[i-1]-1>=0)?dp[i-1][j-c[i-1]-1]:0;
            ll b = dp[i-1][j];
            dp[i][j] = ((b-a+mod)%mod+(i == n?0:dp[i][j-1]))%mod;
        }
    }
    cout<<dp[n][k]<<"\n";
    return 0;
}

