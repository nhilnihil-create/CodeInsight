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
    vector<pair<ll, ll>>r;
    vector<pair<ll, ll>>b;

    for (ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        r.push_back({y, x});
    }
     for (ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        b.push_back({x, y});
    }

    sort(r.begin(), r.end());
    reverse(r.begin(), r.end());
    sort(b.begin(), b.end());
    vector<bool> used(n, false);
    ll  c = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n ; j++) {
       if(b[i].ff > r[j].ss && b[i].ss > r[j].ff && !used[j]) {
        c++;
        used[j] = true;
        break;
       }

    }
    }

    cout << c << endl;
    return 0;
}
