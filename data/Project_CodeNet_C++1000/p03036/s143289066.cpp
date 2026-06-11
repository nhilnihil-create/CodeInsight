#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int r, D;
    vector<int> x(2100, 0);
    cin >> r >> D >> x.at(2000);

    for (int i = 2000; i <= 2010; i++) {
        x.at(i + 1) = r * x.at(i) - D;
    }

    for (int i = 2001; i <= 2010; i++) {
        cout << x.at(i) << endl;
    }

    return 0;
}
