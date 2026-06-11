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
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S.at(i);
    }
    FOR(h, 0, H) {
        FOR(w, 0, W) {
            if (S.at(h).at(w) == '#') {
                cout << '#';
                continue;
            }
            int bom = 0;
            FORE(i, max(0, h - 1), min(h + 2, H)) {
                FORE(j, max(0, w - 1), min(w + 2, W)) {
                    if (S.at(i).at(j) == '#') { ++bom; }
                }
            }
            cout << bom;
        }
        cout << endl;
    }
}
