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
    ll n, m;
    cin >> n >> m;
    ll a, b;
    vector<pair<ll, ll > > v;
    for(int i=0;i<m;i++){
    	cin >> a >> b;
    	v.push_back({b, a});
    }
    sort(be(v));
    ll id = -1;
    ll ans = 0;
    for(auto i: v){
    	if(i.second >= id){
    		id = i.first;
    		ans++;
    	}
    }
    cout << ans << endl;
    return 0;
}
