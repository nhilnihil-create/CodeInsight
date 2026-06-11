#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

int n;
int a[100];

int main() {
    cin >> n;
    rep(i,n) cin >> a[i];
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            ans++;
            a[i] = inf;
        }
    }
    cout << ans << endl;
}