#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    rep(i, 9) {
        char tmp;
        cin >> tmp;
        if (i == 0 || i == 4 || i == 8) cout << tmp;
    }
    cout << endl;
    return 0;
}