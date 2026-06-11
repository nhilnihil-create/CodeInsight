#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> l(n+1, 0), r(n+1, 0);
    for(int i=0;i<n;i++){
    	cin >> l[i] >> r[i];
    }
    sort(be(l));
    reverse(be(l));
    sort(be(r));
    ll ans = 0, sum = 0;
    for(int i=0;i<=n;i++){
    	sum += (l[i] - r[i]) * 2;
    	ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
