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
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    int ans = 0;
    FOR(a, 0, A + 1) {
        FOR(b, 0, B + 1) {
            int c = (X - 500 * a - 100 * b) / 50;
            if ((0 <= c) & (c <= C)) { ++ans; }
        }
    }
    cout << ans << endl;
}
