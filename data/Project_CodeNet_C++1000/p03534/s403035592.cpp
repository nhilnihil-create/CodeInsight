#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

int abs(int a) { return a < 0 ? -a : a; }

int main() {
    string s;
    cin >> s;

    int a, b, c;
    a = b = c = 0;
    for (char i : s) {
        if (i == 'a') {
            a++;
        } else if (i == 'b') {
            b++;
        } else if (i == 'c') {
            c++;
        }
    }

    while (a >= 3 && b >= 3 && c >= 3) {
        a -= 3;
        b -= 3;
        c -= 3;
    }

    bool ans = a <= 3 && b <= 3 && c <= 3 && abs(a - b) <= 1 && abs(b - c) <= 1 &&
               abs(c - a) <= 1;
    cout << (ans ? "YES" : "NO") << endl;

    return 0;
}
