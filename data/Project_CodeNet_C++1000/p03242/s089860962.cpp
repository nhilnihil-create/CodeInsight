#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    string n;
    cin >> n;
    for (auto ch : n) {
        if (ch == '9')
            cout << 1;
        else if (ch == '1')
            cout << 9;
        else
            cout << ch;
    }
}