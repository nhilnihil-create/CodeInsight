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
    vector<ll>v, u;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v.push_back(x);
        u.push_back(x);
    }
    sort(u.begin(), u.end());
    ll l = u[(n/2) - 1];
    ll r = u[n/2];

    for (ll i = 0; i < n; i++) {
        if(v[i] <= l) {
            cout << r << endl;
        }
        else {
            cout << l << endl;
        }
    }
    return 0;
}

