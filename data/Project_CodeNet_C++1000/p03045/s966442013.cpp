#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SIZE = 1e5 * 3 + 10;

vector<vector<ll>> graph;
ll dsu[SIZE];
set<ll> s;
ll find(int v) {
    if (dsu[v] == v) return v;
    else return dsu[v] = find(dsu[v]);
}

void uni(int v, int u) {
    v = find(v);
    u = find(u);
    if (u != v) {
        dsu[u] = v;
    }
}

int main() {
    fastInp;

    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) dsu[i] = i;
    for (int i = 0; i < m; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        z %= 2;
        x--; y--;
        uni(x, y);
    }

    for (int i = 0; i < n; i++) {
        ll v = find(i);
        s.insert(v);
    }

    cout << s.size() << "\n";

    return 0;
}

