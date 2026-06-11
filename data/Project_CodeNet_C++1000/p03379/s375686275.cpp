#include <bits/stdc++.h>
#include <utility>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    int n; cin >> n;
    V<ll> a(n), b(n);
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        a[i] = x;
        b[i] = x;
    }

    sort(all(b));
    ll ml = b[n / 2 - 1];
    ll mr = b[n / 2];

    for(int i = 0; i < n; i++){
        if(a[i] <= ml) cout << mr << endl;
        else if(mr <= a[i]) cout << ml << endl;
    }

}
