#include <bits/stdc++.h>
#define ull uint64_t
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mx5 100005
#define mx6 1000005
#define mod 1000000007
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int h[2*mx5], a[2*mx5];
ll BIT[2*mx5] = {};

ll qry(int h) {
    ll out = 0;
    for (int i = h; i; i ^= i & (-i)) {
        out = max(out, BIT[i]);
    }
    return out;
}

void upd(ll b, int h) {
    for (int i = h; i < 2*mx5; i += i & (-i)) {
        BIT[i] = max(BIT[i], b);
    }
}

int main() {
    nfs
    int i, j, n;
    cin >> n;
    
    for (i = 0; i < n; i++) {
        cin >> h[i];
    }

    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (i = 0; i < n; i++)
        upd(qry(h[i]) + a[i], h[i]);
    
    cout << qry(n);
}