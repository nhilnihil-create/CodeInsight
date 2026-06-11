#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define int ll
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'

const int MOD = (int)1e9 + 7;

signed main() {
    int A, B;

    cin >> A >> B;

    if (A % 2 == 0) {
        int cnt = B - A + 1;
        int r = cnt % 4;
        if (r == 0) {
            cout << 0 << endl;
        } else if (r == 1) {
            cout << B << endl;
        } else if (r == 2) {
            cout << 1 << endl;
        } else {
            cout << (1 ^ B) << endl;
        }

        return 0;
    } else {
        // A が残る
        int cnt = B - A + 1 - 1;
        int r = cnt % 4;
        if (r == 0) {
            cout << A << endl;
        } else if (r == 1) {
            cout << (A ^ B) << endl;
        } else if (r == 2) {
            cout << (A ^ 1) << endl;
        } else {
            cout << ((A ^ 1) ^ B) << endl;
        }

        return 0;
    }



}
