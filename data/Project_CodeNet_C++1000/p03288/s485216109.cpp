#include <bits/stdc++.h>

#define rep(x, y) for (int i = (x); i < (y); i++)

typedef long long ll;

using namespace std;

int main() {
    int r;
    cin >> r;

    if (r < 1200) {
        cout << "ABC";
    } else if (r < 2800) {
        cout << "ARC";
    } else {
        cout << "AGC";
    }
    cout << endl;

    return 0;
}
