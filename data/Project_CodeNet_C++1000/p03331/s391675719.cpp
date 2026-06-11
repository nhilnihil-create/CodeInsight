#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int sumd(int x) {
    int res = 0;
    while (x != 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    int ans = INF;
    for (int i = 1; i < n;++i){
        int j = n - i;

        ans = min(ans, sumd(i) + sumd(j));
    }

    cout << ans << endl;

    return 0;
}