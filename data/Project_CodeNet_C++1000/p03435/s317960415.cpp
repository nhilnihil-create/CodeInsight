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
    vector<vector<int>> c(3, vector<int>(3, 0));
    for (int i = 0; i < 3; i++) {
        cin >> c.at(i).at(0) >> c.at(i).at(1) >> c.at(i).at(2);
    }
    FOR(a1, 0, 101) {
        int a2, a3, b1, b2, b3;
        b1 = c.at(0).at(0) - a1;
        b2 = c.at(0).at(1) - a1;
        b3 = c.at(0).at(2) - a1;
        a2 = c.at(1).at(0) - b1;
        a3 = c.at(2).at(0) - b1;
        if ((a2 == c.at(1).at(1) - b2) && (a2 == c.at(1).at(2) - b3) &&
            (a3 == c.at(2).at(1) - b2) && (a3 == c.at(2).at(2) - b3)) {
            cout << "Yes" << endl;
            exit(0);
        }
    }
    cout << "No" << endl;
}
