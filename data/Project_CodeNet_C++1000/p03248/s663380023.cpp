#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    int b = 1;
    for (int i = 0; i < n; i++) {
        int j = n - 2 - i;
        if (i >= j) break;
        if (s[i] != s[j]) {
            b = 0;
            break;
        }
    }
    if (s[0] == '0' || s.back() != '0') b = 0;

    if (!b) {
        cout << -1 << endl;
        exit(0);
    }

    int p = 0;
    for (int i = 1; i < n; i++) {
        cout << p + 1 << ' ' << i + 1 << '\n';
        if (s[i - 1] != '0') p = i;
    }

    return 0;
}