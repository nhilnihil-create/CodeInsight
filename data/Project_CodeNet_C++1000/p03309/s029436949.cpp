#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define INF LLONG_MAX
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
int main()
{
    ll n; cin >> n;
    vector<ll> a(n);
    REP(i, n) {
        ll num; cin >> num;
        a[i] = num - (i + 1);
    }
    sort(ALL(a));
    if (a.size()) {
        ll middle = a[a.size()/2];
        ll total = 0;
        REP(i, n) {
            total += abs(a[i] - middle);
        }
        cout << total << endl;
        return 0;
    } else {
        ll total1 = 0, total2 = 0;
        REP(i, n) {
            total1 += abs(a[i] - a[a.size()/2]);
            total2 += abs(a[i] - a[a.size()/2-1]);
        }
        cout << min(total1, total2) << endl;
        return 0;
    }
    return 0;
}