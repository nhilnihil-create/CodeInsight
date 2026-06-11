#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> vt(4);
    for (int i = 0; i < 6; ++i) {
        int x;
        cin >> x;
        vt[x - 1]++;
    }

    if (*max_element(vt.begin(), vt.end()) <= 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}