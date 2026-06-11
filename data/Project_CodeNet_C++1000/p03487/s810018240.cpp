#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> a;

    rep(i, n) {
        int x;
        cin >> x;
        a[x]++;
    }

    int ans = 0;
    for (auto e: a) {
        if (e.first < e.second) ans += e.second - e.first;
        else if (e.first > e.second) ans += e.second;
    }

    cout << ans << endl;
    return 0;
}
