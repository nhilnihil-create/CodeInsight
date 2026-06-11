#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    int a = min(N, M);
    int b = max(N, M);
    if (a == 1 && b == 1) cout << 1 << endl;
    else if (a == 1) cout << b - 2 << endl;
    else cout << (ll)(a - 2)*(b - 2) << endl;
    return 0;
}