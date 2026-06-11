#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int cnt[4] = {0};
    rep(i, 6) {
        int a;
        cin >> a;
        --a;
        ++cnt[a];
    }

    int two = 0, one = 0;
    rep(i, 4) {
        if (cnt[i] > 2) {
            cout << "NO" << endl;
            return 0;
        } else if (cnt[i] == 2)
            ++two;
        else if (cnt[i] == 1)
            ++one;
    }

    if(two==one&&one==2)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;

    return 0;
}