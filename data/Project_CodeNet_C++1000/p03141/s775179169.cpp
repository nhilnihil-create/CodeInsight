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
    vector<ll> d(n);
    ll ans=0;
    rep(i,n) {
        ll a,b;
        cin >> a >> b;
        d[i]=a+b;
        ans-=b;
    }
    sort(d.begin(),d.end(),greater<>());
    rep(i,n) {
        if (i%2==0) ans+=d[i];
    }
    cout << ans << endl;
    

    return 0;   
}
