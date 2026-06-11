#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = 3;
    for (int bit = 0; bit < (1 << n); bit++) {
        int sum = s[0] - '0';
        string f = "";
        f += s[0];
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                sum -= s[i + 1] - '0';
                f += "-";
            } else {
                sum += s[i + 1] - '0';
                f += "+";
            }
            f += s[i + 1];
        }
        if (sum == 7) {
            f += "=7";
            cout << f << endl;
            return 0;
        }
    }
    return 0;
}
