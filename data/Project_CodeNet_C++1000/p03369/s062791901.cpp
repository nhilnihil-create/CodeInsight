#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = 0;
    for (char c : s) {
        if (c == 'o') {
            n++;
        }
    }
    cout << 700 + n * 100;
}
