#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll h, w, d;
    cin >> h >> w >> d;
    vector<ll> a(h*w+1), x(h*w+1);
    ll q, c;
    for(ll i=0;i<h;i++){
    	for(ll j=0;j<w;j++){
    		cin >> c;
    		a[c] = i;
    		x[c] = j;
    	}
    }
    vector<ll> b(h*w+1, 0);
    ll le, ri;
    for(int i=1;i<=d;i++){
    	ll now = i;
    	while(now + d <= h * w){
    		ll nx = now + d;
    		b[nx] = b[now] + abs(x[now] - x[nx]) + abs(a[now] - a[nx]);
    		now = nx;
    	}
    }
    cin >> q;
    vector<ll> ans;
    for(int i=0;i<q;i++){
    	cin >> le >> ri;
    	ans.pb(b[ri] - b[le]);
    }
    for(auto& i: ans){
    	cout << i << endl;
    }
    return 0;
}
