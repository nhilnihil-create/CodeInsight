#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int const MAX = 200010;
int cnt[MAX];

int main() {
    int n, k;
    cin >> n >> k;

    rep(i, n) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    sort(cnt, cnt + n + 1, greater<int>());

    int ans = 0, kind = 0;
    rep(i, n) {
        if (cnt[i] != 0) kind++;
    }

    while (kind > k) kind--, ans += cnt[kind];

    cout << ans << endl;
    return 0;
}
