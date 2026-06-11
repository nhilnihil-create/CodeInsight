#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string s;
    int x, y;
    cin >> s >> x >> y;

    int i = 0;
    while (i < sz(s) && s[i] == 'F')
        i++;

    x -= i;

    bool dir = false;
    vi vert, horiz;
    while (i < sz(s)) {
        int j = i + 1;
        while (j < sz(s) && s[j] != 'T')
            j++;
        if (j-i-1) (dir ? horiz : vert).push_back(j-i-1);
        i = j;
        dir = !dir;
    }

    const int MAXV = 8008;
    bitset<2 * MAXV> v, h;
    v[MAXV] = true;
    h[MAXV] = true;

    for (int d : vert) v = (v << d) | (v >> d);
    for (int d : horiz) h = (h << d) | (h >> d);

    if (x + MAXV < 0) cout << "No\n";
    else cout << (v[y + MAXV] && h[x + MAXV] ? "Yes\n" : "No\n");

    return 0;
}

