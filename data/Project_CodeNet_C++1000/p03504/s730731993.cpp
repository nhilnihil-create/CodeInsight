#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using Graph = vector<vector<pii>>;
const int MOD = 1e9 + 7;

struct prog {
    int s, t, c;
};

bool operator<(prog a, prog b) {
    return (a.c == b.c ? a.s < b.s : a.c < b.c);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, C;
    cin >> N >> C;

    vector<prog> dat(N);
    for (int i = 0; i < N; ++i)
        cin >> dat[i].s >> dat[i].t >> dat[i].c;

    sort(dat.begin(), dat.end());
    vector<int> cnt(100005);
    for (int i = 0; i < N; ++i) {
        cnt[dat[i].s - 1]++;
        if (i + 1 < N && dat[i].c == dat[i + 1].c && dat[i].t == dat[i + 1].s) {
            cnt[dat[i + 1].s - 1]--;
            continue;
        }
        cnt[dat[i].t]--;
    }

    int ans = 0;
    for (int i = 0; i <= 100000; ++i) {
        cnt[i + 1] += cnt[i];
        ans = max(ans, cnt[i]);
    }
    cout << ans << endl;

    return 0;
}
