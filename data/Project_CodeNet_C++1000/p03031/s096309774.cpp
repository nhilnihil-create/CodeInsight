//
// author  : Abhishek
//
#include <bits/stdc++.h>

#define ll long long
#define db double
#define deb(x) cout<<#x<<": "<<x<<"\n"
#define all(x) x.begin(),x.end()
#define fo(i, n) for(i=0 ; i<n ; i++)
#define Fo(i, k, n) for(i=k ; i<n ; i++)

using namespace std;

const ll mod = 1000000007;
const ll N = 200005;  // array size
const ll inf = 10000000000000000;


void print(vector<ll> v) {
    ll i;
    fo(i, v.size())cout << v[i] << " ";
    cout << "\n";
}

vector<ll> read(ll n) {
    ll i;
    vector<ll> arr(n, 0);
    fo(i, n)cin >> arr[i];
    return arr;
}

vector<ll> read(ll n, ll k) {
    ll i;
    vector<ll> arr(n + k, 0);
    Fo(i, k, n + k)cin >> arr[i];
    return arr;
}

bool isEven(ll n) {
    return n % 2 == 0;
}

bool isOdd(ll n) {
    return n % 2 == 1;
}


void solve() {
    ll t;
    cin >> (t);
    while (t--) {

        ll i, j, k, n, m, p, q, x, y, a, b, l, r;


    }
}

int main() {


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j, k, n, m, q, x, y, a, b, l, r;

    cin >> n >> m;
    vector<ll> adj[m];

    fo(i, m) {
        cin >> k;
        fo(j, k) {
            cin >> x;
            x--;
            adj[i].push_back(x);
        }
    }

    vector<ll> p;
    p = read(m);

    ll mask = 0;

    ll ans = 0;
    for (mask = 0; mask < (1 << n); mask++) {
        bool ok = 1;

        for (i = 0; i < m; i++) {
            ll ct = 0;
            for (auto on : adj[i]) {
//                deb(on);
                if (mask & (1 << on)) {
                    ct++;
                }
            }
            if (ct % 2 != p[i] % 2 ) {
                ok = 0;
            }
        }
        if(ok)
            ans++;
    }
    cout << ans;


    return 0;
}


