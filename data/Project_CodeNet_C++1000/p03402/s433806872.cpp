#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9+7;

int main() {
    int A, B;
    cin >> A >> B;
    cout << 100 << " " << 100 << endl;
    vector<vector<char>> g(100);
    REP(i, 50) {
        g[i].resize(100);
        fill(ALL(g[i]), '#');
    }
    FOR(i, 50, 100) {
        g[i].resize(100);
        fill(ALL(g[i]), '.');
    }

    int c = 0;
    for(int i = 0;i < 50;i += 2) {
        for(int j = 0;j < 100 && c < A - 1;j += 2, c++) {
            g[i][j] = '.';
        }
    }

    int d = 0;
    for(int i = 99;50 <= i;i -= 2) {
        for(int j = 0;j < 100 && d < B - 1;j += 2, d++) {
            g[i][j] = '#';
        }
    }
    REP(i, 100) {
        REP(j, 100) {
            cout << g[i][j];
        }
        cout << endl;
    }
    return 0;
}

