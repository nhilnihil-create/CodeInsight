#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define sd second
#define ll long long

using namespace std;

const int maxn = 100100;
const ll oo = 1e18;

int n;
pair<ll, ll> x[maxn];
ll f[maxn][3],c;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
  //  freopen("in.txt","r",stdin);
    cin>>n>>c;
    for (int i=1;i<=n;i++) cin>>x[i].fi>>x[i].sd;
    sort(x+1,x+n+1);
    ll now=0;
   // for (int i=1;i<=n;i++) cout<<x[i].fi<<" "<<x[i].sd<<endl;
    for (int i=1;i<=n;i++) {
        now += x[i].sd;
        for (int j=1;j<=2;j++) f[i][j] = max(f[i-1][j], now - 1ll*j*x[i].fi);
    }


    ll ans = f[n][1];
    now =0;
    for (int i=n;i>=1;i--) {
        now += x[i].sd;
       // cout<<x[i].sd<<endl;
        ans = max(ans,f[i-1][1] + now - 2*(c-x[i].fi));
       // cout<<i<<" "<<ans<<" "<<f[i][1]<<endl;
        ans = max(ans,f[i-1][2] + now - (c-x[i].fi));
      //  cout<<i<<" "<<ans<<" "<<f[i][2]<<endl;
    }

    cout<<ans<<endl;

}
