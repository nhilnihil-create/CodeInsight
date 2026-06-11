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
    ll n, m, sum = 0;
    cin >> n >> m;
    vector<ll> a(m), b;
    for(int i=0;i<m;i++){
    	cin >> a[i];
    }
    n = min(n - 1, m - 1);
    sort(be(a));
    for(int i=1;i<m;i++){
    	b.pb(a[i] - a[i-1]);
    	sum += a[i] - a[i-1];
    }
    sort(be(b));
    reverse(be(b));
    for(int i=0;i<n;i++){
    	sum -= b[i];
    }
    cout << sum << endl;
    return 0;
}
