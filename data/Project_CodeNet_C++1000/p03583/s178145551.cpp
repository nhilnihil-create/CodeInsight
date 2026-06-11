#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)

const int MAX = 3501;
ll N;

void solve() {
    FOR (h, 1, MAX) FOR (n, 1, MAX) {
        ll a = N*h*n;
        ll b = 4*h*n - N*n - N*h;
        if (a >= 1 && b >= 1 && a%b == 0) {
            cout << h << " " <<  n << " " << (a/b) << endl;
            return;
        }
    }
}

int main() {
    cin >> N;
    solve();
}