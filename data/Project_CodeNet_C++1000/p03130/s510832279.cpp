#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int main() {
    vector<int> vec(4);
    rep(i, 6) {
        int tmp;
        cin >> tmp;
        vec[tmp - 1] += 1;
    }
    int one = 0, two = 0;
    rep(i, 4) if (vec[i] == 1) one += 1; else if (vec[i] == 2) two += 1;
    if (two == 2 && one == 2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}