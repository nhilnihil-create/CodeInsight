#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

double bitToJPN(double bit) {
    return bit * 380000.0;
}

int main() {
    fastIO;
    int n;
    cin >> n;

    double sum = 0.0;
    rep(_, n) {
        double bit;
        cin >> bit;

        string curr;
        cin >> curr;

        if (curr == "BTC") {
            sum += bitToJPN(bit);
        } else {
            sum += bit;
        }
    }
    cout << precise(6) << sum << endl;
}