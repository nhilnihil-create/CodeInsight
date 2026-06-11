#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
    int n; cin >> n;
    vector<int> v(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (i % j == 0) ++v[i];
        }
    }

    int rtn = 0;
    for (int i = 1; i <= n; ++i)
        if (i % 2 != 0 && v[i] == 8) ++rtn;

    cout << rtn << endl;
}
