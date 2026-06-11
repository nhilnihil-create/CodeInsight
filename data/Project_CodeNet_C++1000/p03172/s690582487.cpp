#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define snd second
#define ALL(s) s.begin(),s.end()
#define fore(i,x,y) for(ll i=x;i<y;i++)
#define SZ(x) ((int)(x).size())
#define PI acos(-1)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
using namespace std;

const ll mod = 1e9+7;
const int MAXN = 1e5+10;
ll dp[105][MAXN];

int main() {FIN;
    int n,k; cin>>n>>k;
    memset(dp,0,sizeof(dp));
    vector<int> v(n);
    fore(i,0,n) cin>>v[i];
    fore(i,0,v[0]+1) dp[0][k-i] = 1;
    fore(i,1,n){
        ll sum = 0;
        for(int j = k; j >=0; j--){
            sum = (sum +dp[i-1][j])%mod;
            dp[i][j] = sum;
            if(k-j>=v[i]) sum = (sum - dp[i-1][j+v[i]] + mod)%mod;
        }
    }
    cout<<dp[n-1][0]<<"\n";
    return 0;
}

