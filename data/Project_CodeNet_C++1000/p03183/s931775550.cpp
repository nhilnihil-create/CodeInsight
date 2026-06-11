#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1087, C = 2e4 + 87;
ll dp[C];
tuple<int, int, int> a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int w, s, v;
        cin >> w >> s >> v;
        s += w;
        a[i] = make_tuple(s, w, v);
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        int s, w, v;
        tie(s, w, v) = a[i];
        for (int j = s; j >= w; --j)
            dp[j] = max(dp[j], dp[j - w] + v);
        for (int j = s + 1; j < C; ++j)
            dp[j] = max(dp[j], dp[j - 1]);
    }
    cout << dp[C - 1] << endl;
}
