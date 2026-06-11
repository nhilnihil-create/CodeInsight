#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>
#include <math.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repf(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define repr(i, a, b) for (ll i = (ll)a; i > (ll)b; i--)
#define repv(x, arr) for (auto &x : arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a, b) make_pair(a, b)
#define pb(x) push_back(x)
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int infi = 2147483600;
const ll infl = 1e17;


int main()
{
    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    vll b(n);
    rep(i, n) cin >> b[i];
    ll ans = 0;
    rep(k,29){
        ll two = (1 << (k+1));
        ll t = (1 << k);
        ll cnt = 0;
        vll c(n);
        rep(i, n) c[i] = b[i] % two;
        sort(all(c));
        rep(i,n){
            ll idx1, idx2, idx3, idx4;
            idx1 = lower_bound(all(c), max(0ll,(t - (a[i] % two)))) - c.begin();
            idx2 = lower_bound(all(c), 2*t - (a[i] % two)) - c.begin();
            idx3 = lower_bound(all(c), 3*t - (a[i] % two)) - c.begin();
            idx4 = lower_bound(all(c), 4*t - (a[i] % two)) - c.begin();
            cnt += (idx2 - idx1 + idx4 - idx3) % 2;
        }
        ans += (1 << k) * (cnt % 2);
    }
    cout << ans << endl;
}
