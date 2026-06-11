#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;

ii P[200002];

int main() {
    if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);

    int H, W, N; cin >> H >> W >> N;
    for (int i = 0; i < N; ++i) cin >> P[i].f >> P[i].s;
    sort(P, P+N);
    for (int i = 0, c = 0; i < N; ++i) {
        if (P[i].s+c < P[i].f) {
            cout << P[i].f-1;
            return 0;
        }
        if (P[i].s+c == P[i].f) ++c;
    }
    cout << H;
    return 0;
}
