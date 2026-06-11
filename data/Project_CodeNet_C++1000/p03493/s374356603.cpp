#include <iostream>

using namespace std;

int main() {
    string s;
    int t = 0;
    cin >> s;
    for (char c : s) {
        if (c == '1') {
            t++;
        }
    }
    cout << t;
}
