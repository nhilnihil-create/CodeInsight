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
    ll n, x; 
    cin >> n >> x;
    ll a[n];
    for(int i=0;i<n;i++){
    	cin >> a[i];

    }
    vector<ll> b;
    for(int i=1;i<n;i++){
    	b.pb(abs(a[i] - a[i-1]));
    }
    b.pb(abs(a[0] - x));
    ll g = b[0];
    for(auto& i: b){
    	g = __gcd(g, i);
    }
    cout << g << endl;
    return 0;
}
