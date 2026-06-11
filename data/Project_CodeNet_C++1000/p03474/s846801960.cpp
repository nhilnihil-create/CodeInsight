#include <string>
#include <iostream>

using namespace std;

void No() {
    cout << "No" << endl;
    exit(0);
}

void Yes() {
    cout << "Yes" << endl;
    exit(0);
}

int main() {
    int a, b;
    string s;
    cin >> a >> b >> s;
    for (int i = 0; i < a; ++i) {
        if (!('0' <= s[i] && s[i] <= '9')) {
            No();
        }
    }
    if (s[a] != '-') {
        No();
    }
    for (int i = a + 1; i < a + b + 1; ++i) {
        if (!('0' <= s[i] && s[i] <= '9')) {
            No();
        }
    }
    Yes();
}
