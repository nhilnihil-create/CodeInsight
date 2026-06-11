#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <string.h>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
double PI = 3.1415926535897932;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

ll n, X;
ll x[200000];
ll sum[200000];

int main() {
    cin >> n >> X;
    rep(i,n) cin >> x[i];
    rep(i,n) {
        sum[i] = (i==0?0:sum[i-1]) + x[i];
    }
    ll ans = linf;
    for (ll i = n; i >= 1; i--) {
        ll cnt = 1;
        ll now = (sum[n-1] - (i==n?0:sum[n-1-i]))*2;
        for (ll j = n-1; j >= 0; j -= i) {
            now = now + (sum[j]-(j<i?0:sum[j-i])) * ((cnt+1)*(cnt+1)-cnt*cnt);
            if (now > ans) break;
            cnt++;
        }
        ans = min(ans, now+i*X+n*X);
    }
    cout << ans << endl;
}