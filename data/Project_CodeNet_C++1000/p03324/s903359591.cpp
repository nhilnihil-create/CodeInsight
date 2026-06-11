#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

const int MOD = (int) 1e9 + 7;

int main()
{
    int d, n;
    cin >> d >> n;
    if(d == 0) {
        if(n == 100) cout << 101 << endl;
        else cout << n << endl;
    }
    if(d == 1) {
        if(n == 100) cout << 10100 << endl;
        else cout << 100 * n << endl;
    }
    if(d == 2) {
        if(n == 100) cout << 1010000 << endl;
        else cout << 10000 * n << endl;
    }
    return 0;
}
