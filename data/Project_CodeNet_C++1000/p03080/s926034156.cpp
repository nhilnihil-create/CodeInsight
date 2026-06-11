#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n, x, y;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') {
            ++x;
        } else {
            ++y;
        }
    }
    if (x > y) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
