#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r;
    cin >> r;
    if (r < 1200) {
        cout << "ABC";
    } else if (r < 2800) {
        cout << "ARC";
    } else {
        cout << "AGC";
    }
}