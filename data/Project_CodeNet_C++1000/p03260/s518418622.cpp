#include <bits/stdc++.h>

#define rep(x, y) for (int i = (x); i < (y); i++)

typedef long long ll;

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    bool found = false;
    rep(1, 4) {
        if (a * b * i % 2 != 0) {
            found = true;
            break;
        }
    }

    cout << (found ? "Yes" : "No") << endl;

    return 0;
}