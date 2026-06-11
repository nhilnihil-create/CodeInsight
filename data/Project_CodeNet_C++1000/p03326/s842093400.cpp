#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
const int MOD=1e9+7;


int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<ll>> s(8);
    rep(i,n) {
        vector<ll> x(3);
        cin >> x[0] >> x[1] >> x[2];
        rep(bit,8) {
            ll total=0;
            rep(k,3) {
                if (bit & (1<<k)) total+=-x[k];
                else total+=x[k];
            }
            s[bit].push_back(total);
        }
    }
    ll ans=-1e9;
    rep(j,8) {
        sort(s[j].begin(),s[j].end(),greater<>());
        ll tans=0;
        rep(i,m) tans+=s[j][i];
        ans=max(ans,tans);
    }
    cout << ans << endl;
}