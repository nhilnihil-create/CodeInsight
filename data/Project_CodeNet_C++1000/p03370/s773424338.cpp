#include <bits/stdc++.h>
#define INF 1e9
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define FORE(i, a, b) for (int i = (a), e = (b); i < e; ++i)
#define RFORE(i, a, b) for (int i = (b)-1, e = (a); i >= e; --i)
#define ALL(x) (x).begin(), (x).end()
#define SORT(c) sort((c).begin(), (c).end())
#define SORTR(c) sort((c).begin(), (c).end(), greater<int>())
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, X;
    cin >> N >> X;
    vector<int> m(N);
    for (int i = 0; i < N; i++) {
        cin >> m.at(i);
    }
    SORT(m);
    X -= accumulate(ALL(m), 0);
    int ans = 0;
    while (true) {
        X -= m.at(0);
        if (X < 0) {
            break;
        } else if (X == 0) {
            ++ans;
            break;
        }
        ++ans;
    }
    cout << ans + N << endl;
}
