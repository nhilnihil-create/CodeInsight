#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const int MOD=1e9+7;



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> f(n,vector<int>(10));
    rep(i,n) {
        rep(j,10) cin >> f[i][j];
    }
    vector<vector<ll>> p(n,vector<ll>(11));
    rep(i,n) {
        rep(j,11) cin >> p[i][j];
    }
    ll ans=-10e9;
    repr(bit,1,(1<<10)) {
        ll tans=0;
        rep(i,n) {
            int cnt=0;
            rep(j,10) {
                if ((bit & (1<<j))>0 && f[i][j]==1) {
                    ++cnt;
                }
            }
            tans+=p[i][cnt];
        }
        ans=(tans>ans)?tans:ans;
    }

    cout << ans  << endl;


    return 0;   
}
