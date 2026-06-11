#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, Y;
    cin >> n >> Y;
    Y /= 1000;
    int ansx = -1;
    int ansy = -1;
    int ansz = -1;
    rep(x, n + 1) {
        rep(y, n - x + 1) {
            if(9 * x + 4 * y == Y - n) {
                ansx = x;
                ansy = y;
                break;
            }
        }
    }
    if(n - ansx - ansy >= 0 && ansx != -1 && ansy != -1) {
        ansz = n - ansx - ansy;
    }
    cout << ansx << " " << ansy << " " << ansz << endl;
    return 0;
}