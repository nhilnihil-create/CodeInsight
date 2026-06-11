#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair
#define sz(x)       int(x.size())
//#define int         int64_t

using namespace std;

typedef pair<int, int> pii;
const int N = 2002;
const int M = 2000 * 2000 + 2;

bitset<M> f;
int s, x, n;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n; f.set(0);
    for(int i = 1; i <= n; ++i) {
        cin >> x; s += x;
        f |= (f << x);
    }
    for(int i = (s + 1) >> 1; i <= s; ++i) {
        if(f[i]) return cout << i, 0;
    }
}
