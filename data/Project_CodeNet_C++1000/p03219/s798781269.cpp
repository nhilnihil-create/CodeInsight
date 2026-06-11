#include <bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                                                       \
    for(long long hoge = 0; (hoge) < (n); ++(hoge))                            \
    cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

using ll = long long;
const ll INF = LLONG_MAX / 2;

signed main() {
    int x, y;
    cin >> x >> y;
    cout << x + y / 2 << endl;
    return 0;
}
