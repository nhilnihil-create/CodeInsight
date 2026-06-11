#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)

int main(){
    ll n; cin >> n; ll ans = 0;
    vector<ll> l(n); vector<ll> r(n);
    REP(i,n) cin >> l[i] >> r[i];
    l.push_back(0); r.push_back(0);
    sort(l.rbegin(),l.rend()); sort(r.begin(),r.end());
    REP(i,n) if (l[i]>r[i]) ans += l[i]-r[i];
    cout << ans*2 << endl;
}