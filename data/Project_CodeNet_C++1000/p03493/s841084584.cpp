#include <bits/stdc++.h>

using namespace std;

int main() {
    int res = 0;
    for (int i = 0; i < 3; i++) {
        char c;
        cin >> c;
        res += c - '0';
    }
    cout << res;
    return 0;
}