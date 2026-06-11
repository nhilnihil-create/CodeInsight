#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#define rep(i, n) for(int i=0;i<(int)(n);++i)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long n;
    cin >> n;
    vector<long> vec;
    for (int i = 1, a; i <= n; ++i) {
        cin >> a;
        if (i < a) {
            cout << -1 << '\n';
            return 0;
        }
        vec.insert(vec.begin() + a - 1, a);
    }
    for (int i : vec) {
        cout << i << '\n';
    }
    return 0;
}
