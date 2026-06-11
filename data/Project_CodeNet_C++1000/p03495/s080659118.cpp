#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mx = 10000007;
const ll mod = 1e9 + 7;
const double pi = acos(-1);
#define    ss   second
#define    ff   first
#define    pb   push_back
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
#define FIO ios_base::sync_with_stdio(false);  cin.tie(NULL);


int main() {
    FIO;
    ll n, k;
    cin >> n >> k;
    map<ll, ll>m;
    set<ll>su;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        m[x]++;
        su.insert(x);
    }
    if( su.size() <= k) {
        cout << 0 << endl;
        return 0;
    }
    vector<pair<ll, ll>>v;
    for (auto i = m.begin(); i != m.end(); i++) {
        v.push_back({i->second, i->first});
    }
    ll s = 0;
    sort(v.begin(), v.end());
    for(ll i = 0; i < su.size() - k; i++) {
        s += v[i].first;
    }
    cout << s << endl;
}

