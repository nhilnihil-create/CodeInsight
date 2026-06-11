#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int a = s[0] - '0';
    int b = s[1] - '0';
    int c = s[2] - '0';
    int d = s[3] - '0';

    for (int bit = 0; bit < (1 << 3); bit++) {
        int ans = a;
        string ope;
        if (bit & (1 << 0)) {
            ans += b;
            ope += "+";
        } else {
            ans -= b;
            ope += "-";
        }

        if (bit & (1 << 1)) {
            ans += c;
            ope += "+";
        } else {
            ans -= c;
            ope += "-";
        }

        if (bit & (1 << 2)) {
            ans += d;
            ope += "+";
        } else {
            ans -= d;
            ope += "-";
        }

        if (ans == 7) {
            cout << a << ope[0] << b << ope[1] << c << ope[2] << d << "=7"
                 << endl;
            return 0;
        }
    }
}