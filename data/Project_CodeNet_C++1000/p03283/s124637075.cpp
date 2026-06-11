#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

ll dp[510][510];

int main(){
    int n,m,Q;
    cin >> n >> m >> Q;
    rep(i,510){
        rep(j,510){
            dp[i][j]=0;
        }
    }
    rep(i,m){
        int l,r;
        cin >> l >> r;
        dp[l][r]++;
    }
    rep(i,510){
        rep(j,509){
            dp[i][j+1]+=dp[i][j];
        }
    }
    rep(i,Q){
        int p,q;
        cin >> p >> q;
        ll res = 0;
        for(int j=p;j<=q;j++){
            res += dp[j][q]-dp[j][p-1];
        }
        cout << res << endl;
    }


    return 0;
}
