#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> d(3);

    for (int i = 0; i < 3; i++) {
        cin >> d.at(i);
    }
    sort(d.begin(), d.end());

    int x = d.at(2) - d.at(1);
    int y = d.at(2) - d.at(0);
    int ans;

    if (x % 2 == 0 && y % 2 == 0) {
        ans = x / 2 + y / 2;
    }

    else if (x % 2 == 1 && y % 2 == 1) {
        ans = x / 2 + y / 2 + 1;
    }

    else {
        ans = x / 2 + y / 2 + 2;
    }

    cout << ans << endl;
}
