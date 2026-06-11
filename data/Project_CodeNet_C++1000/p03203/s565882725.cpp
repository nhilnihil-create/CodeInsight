#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h, w, n, x, y, ans = 0;
    cin >> h >> w >> n;
    ans = h;
    vector < pair < int, int > > Q;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        Q.push_back({x, y});
    }
    sort(Q.begin(), Q.end());
    int d = 0;
    for (int i = 0; i < (int)Q.size(); ++i) {
        if (Q[i].first - d == Q[i].second) d++;
        if (Q[i].second < Q[i].first - d) {
            ans = Q[i].first - 1;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}

