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
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    if (A + B > 2 * C) {
        // ABピザ2枚を組みかえ
    }
    vector<int> p(1e5 + 1);
    for (int i = 0; i < 1e5 + 1; i++) {
        p.at(i) = i * 2 * C + max(0, X - i) * A + max(0, Y - i) * B;
    }
    cout << *min_element(ALL(p)) << endl;
}
