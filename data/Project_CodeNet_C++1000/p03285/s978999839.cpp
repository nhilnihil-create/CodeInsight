#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long int;
using namespace std;
int main() {
    fastIO;
    int n;
    cin >> n;

    for (int i = 0; i <= 15; i++) {
        for (int j = 0; j <= 25; j++) {
            if (n == i * 7 + j * 4) {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";
    return 0;
}