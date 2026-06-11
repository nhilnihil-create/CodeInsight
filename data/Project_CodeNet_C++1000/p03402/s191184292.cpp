#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

signed main(){
    ll A, B;
    cin >> A >> B;
    char grid[100][100];
    REP(i, 50) REP(j, 100) grid[i][j] = '#';
    FOR(i, 50, 100) REP(j, 100) grid[i][j] = '.';
    REP(i, A - 1){
        grid[2 * (i / 50)][(2 * i) % 100] = '.';
    }
    REP(i, B - 1){
        grid[99 - 2 * (i / 50)][(2 * i) % 100] = '#';
    }
    cout << 100 << " " << 100 << endl;
    REP(i, 100){
        REP(j, 100) cout << grid[i][j];
        cout << endl;
    }
    return 0;
}