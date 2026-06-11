#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

#define ll long long

int k;
ll a[100000];

bool ok(ll n) {
    for (int i=0; i<k; i++) {
        n -= n%a[i];
    }
    return n>=2;
}

bool ok1(ll n) {
    for (int i=0; i<k; i++) {
        n -= n%a[i];
    }
    return n<=2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k;
    for (int i=0; i<k; i++) {
        cin >> a[i];
    }
    ll lo = 0, hi = 2e18+21;
    while (hi-lo > 1) {
        ll mi = (lo+hi)/2;
        if (ok(mi)) {
            hi = mi;
        } else {
            lo = mi;
        }
    }
    ll ansl = hi;
    lo = 0, hi = 2e18+21;
    while (hi-lo > 1) {
        ll mi = (lo+hi)/2;
        if (ok1(mi)) {
            lo = mi;
        } else {
            hi = mi;
        }
    }
    ll ansr = lo;
    if (ansl > ansr) {
        cout << "-1\n";
    } else {
        cout << ansl << " " << ansr << '\n';
    }
    return 0;
}
