#include <iostream>
using namespace std;

int main() {
    int n, result = 0;
    cin >> n;
    string s[n];
    for (int i = 0; cin >> s[i]; i++) {
    }
    for (int b = 0; b < n; b++) {
        bool symetric = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][(j + b) % n] != s[j][(i + b) % n]) {
                    symetric = false;
                }
            }
        }
        if (symetric) {
            result++;
        }
    }
    cout << result * n;
    return 0;
}
