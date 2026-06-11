#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 4e5 + 10;
const int maxm = 1e5 + 10;
const int mod = 1e9 + 7;
const int inf = 1e9;

ll a[maxn], b[maxn], c[maxn], fen[maxn];
ll n;
int N = 200000;

ll get (ll x) {
    ll ret = 0;
    x += N;
    for (; x; x -= x & -x)
        ret += fen[x];
    return ret;
}

void update (ll x) {
    x += N;
    for (; x < maxn; x += x & -x)
        fen[x] ++;
}

ll check () {
    memset (fen, 0, sizeof fen);
    memset (c, 0, sizeof c);
    for (int i = 1; i <= n; i++)
        c[i] = c[i - 1] + b[i] - (b[i] == 0);

    update (0);
    ll ret = 0;
    for (int i = 1; i <= n; i++) {
        ret += get (c[i] - 1);
        update (c[i]);
    }
    return ret;
}

void build (ll x) {
    for (int i = 1; i <= n; i++)
        b[i] = (a[i] < x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll tot = n * (n + 1) / 2;
    ll lo = 0, hi = 1000ll * 1000 * 1000 * 1000 + 1;
    while (hi - lo > 1) {
        ll mid = (lo + hi) >> 1;
        build (mid);
//      cout << lo << " " << mid << " " << hi << " -> " << check () << " " <<  tot / 2 + 1 << endl;
        if (check () > tot / 2)
            hi = mid;
        else
            lo = mid;
    }
    cout << lo << endl;
}