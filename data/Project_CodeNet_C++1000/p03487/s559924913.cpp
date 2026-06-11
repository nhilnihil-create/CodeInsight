#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int N, a, ans = 0;
    cin >> N;
    map<int, int> m;
    rep(i, N) {
        cin >> a;
        m[a]++;
    }
    for (auto i : m) {
        if (i.second >= i.first) ans += i.second - i.first;
        else ans += i.second;
    }
    cout << ans << "\n";
}