#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using ll = unsigned long long int;
using namespace std;

bool isdigit(char ch) {
    return '0' <= ch && ch <= '9';
}

int main() {
    fastIO;

    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;

    if ((int)s.size() != (a + b + 1)) {
        cout << "No";
        return 0;
    }

    for (int i = 0; i < a; i++) {
        if (!isdigit(s.at(i))) {
            cout << "No";
            return 0;
        }
    }

    if (s.at(a) != '-') {
        cout << "No";
        return 0;
    }

    for (int i = a + 1; i < a + b; i++) {
        if (!isdigit(s.at(i))) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
}