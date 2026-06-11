#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    vector<int> N(5);
    rep(i, 5) cin >> N[i];
    int k;
    cin >> k;

    int last = 0;
    int mini = 10;
    rep(i, 5) if (N[i] % 10 != 0 && N[i] % 10 < mini) {
        mini = N[i] % 10;
        last = i;
    }
    
    int ans = 0;
    rep(i, 5) {
        if (N[i] % 10 == 0 || i == last) ans += N[i];
        else ans += (N[i] / 10) * 10 + 10;
    }

    cout << ans << endl;
}