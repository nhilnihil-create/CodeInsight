#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;





int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    ll n;
    cin>>n;

    vector<ll> f;
    for (ll i=1; i*i<=n; i++) {
	if (n%i==0) {
	    f.push_back(i);
	    f.push_back(n/i);
	}
    }

    sort(f.begin(), f.end());
    f.erase(unique(f.begin(),f.end()),f.end());




    ll res = 0;

    for (ll k: f) {
	ll m = n/k - 1;
	if (m>0 && k<m) {
	    //cout<<k<<": "<<m<<endl;
	    res += m;
	}
    }


    cout<<res<<endl;
    
    
    return 0;
}
