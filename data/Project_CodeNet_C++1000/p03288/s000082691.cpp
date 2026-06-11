#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    int R;
    cin >> R;
    if (R < 1200)
        cout << "ABC";
    else if (R < 2800)
        cout << "ARC";
    else
        cout << "AGC";
}