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
    ll n;
    cin >> n;
    map<ll, ll>m;
     for (ll i = 0; i < n; i++) {
        m[i] = 0;
    }
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        m[x]++;
    }
    vector<pair<ll, ll>>v;
    for (auto i = m.begin(); i != m.end(); i++) {
        v.push_back({i->first, i->second});
    }
    ll s = 0;
    for(ll i = 0; i < v.size(); i++) {
        if( v[i].first == (i) && v[i].second > 0) {
            if(v[i].second >= i)
            s += abs((i) - v[i].ss);
        else {
            s += v[i].ss;
        }
        }
    else if( v[i].first != (i)) {
            s +=  v[i].ss;
        }
    }

    cout << s << endl;
}

