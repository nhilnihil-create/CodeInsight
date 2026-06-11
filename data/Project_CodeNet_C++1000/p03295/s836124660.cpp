#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll inf = 10000000;

int main() {
    int N, M;
    int ans = 0;
    cin >> N >> M;
    vector<pair<int, int>>ab(M);
    for (int i = 0; i < M; i++) {
        cin >> ab[i].first >> ab[i].second;
    }
    sort(ab.begin(), ab.end());
    int l, r;
    l = 0;
    r = inf;
    for (int i = 0; i < M; i++) {
        if (r <= ab[i].first) {
            ans++;
            r = inf;
        }
        l = max(l, ab[i].first);
        r = min(r, ab[i].second);
    }
    if (r != inf) {
        ans++;
    }
    cout << ans << endl;
}
