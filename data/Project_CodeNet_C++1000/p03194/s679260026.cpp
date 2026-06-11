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

    ll n, p;
    cin>>n>>p;

    map<ll,ll> mp;
    for (ll i=2; i*i<=p; i++) {
	while (p%i==0) {
	    mp[i]++;
	    p/=i;
	}
    }
    if (p>1) mp[p]++;


    ll res = 1;
    for (auto x: mp) {
	ll pw = x.second/n;
	while (pw--) res *= x.first;
    }

    cout<<res<<endl;    
    return 0;
}
