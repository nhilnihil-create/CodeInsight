#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 lll;
constexpr ll mod = 1000000007;

ull pow2(ull n) {
    ull r = 1;
    for (ull i = 0; i < n; i++) r *= 2;
    return r;
}

int main() {
    ull m, k;
    cin >> m >> k;
    if (k >= pow2(m)) goto no_ans;
    if (m == 0) {
        if (k == 0) {
            cout << "0 0" << endl;
            return 0;
        }
        goto no_ans;
    }
    if (m == 1) {
        if (k == 0) {
            cout << "0 1 1 0" << endl;
            return 0;
        }
        goto no_ans;
    }
    for (ull i = 0; i < pow2(m); i++) if (i != k) cout << i << " ";
    cout << k << " ";
    for (ull i = pow2(m); i > 0; i--) if (i - 1 != k) cout << i - 1 << " ";
    cout << k << endl;
    return 0;
    no_ans:
    cout << -1 << endl;
}