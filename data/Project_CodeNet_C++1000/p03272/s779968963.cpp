#include <bits/stdc++.h>

#define NREP() for(ll i = 0; i < n; i++)
#define MREP() for(ll j = 0; j < m; j++)
#define REP(i, x, y) for(ll i = x; i < y; i++)
#define ALL(x) (x).begin(), (x).end()
#define MSG(x) cout << x << endl;
#define END(x) cout << x << endl; exit(0);
#define YN(x) x ? cout << "YES" << endl : cout << "NO" << endl;
#define Yn(x) x ? cout << "Yes" << endl : cout << "No" << endl;
#define yn(x) x ? cout << "yes" << endl : cout << "no" << endl;

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;

const static ll MOD = 1e9 + 7;
ll n, cnt, ans, tmp, sum, minimum, maximum, a, b, c, d, k, m, h, w, q, x, y;
string s, t;

int calc(ll n) {
    ll c = 0;
    for (k = 1; k <= n; k++) {
        if (n % k == 0) c++;
    }
    return c;
}

int main() {
    cin >> n >> x;
    MSG(n - x + 1)
}
