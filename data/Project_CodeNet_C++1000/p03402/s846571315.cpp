#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int main(){
    int a, b;
    cin >> a >> b;
    char c[100][100];
    rep(i, 50) rep(j, 100) c[i][j] = '#';
    rep(i, 50) rep(j, 100) c[i+50][j] = '.';

    int x = 1, y = 1;
    rep(j, a - 1){
        c[y][x] = '.';
        if (x + 2 < 100) x += 2;
        else y += 2, x = 1;
    }

    x = 1, y = 51;
    rep(j, b - 1){
        c[y][x] = '#';
        if (x + 2 < 100) x += 2;
        else y += 2, x = 1;
    }

    cout << 100 << " " << 100 << endl;
    rep(i, 100) {
        rep(j, 100) cout << c[i][j];
        cout << endl;
    }

    return 0;
}
