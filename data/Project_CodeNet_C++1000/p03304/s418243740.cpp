#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int n, m, d; cin >> n >> m >> d;

    cout << fixed << setprecision(15);
    if (d == 0) {
        cout << (double)(m - 1) / n << endl;
    } else {
        cout << (double)(m - 1) * 2 * (n - d) / n / n << endl;
    }
    return 0;
}