#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    int min = 0, max = 0, tmp;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        if (tmp < x) {
            min++;
        } else {
            max++;
        }
    }

    cout << (min < max ? min : max) << endl;

    return 0;
}
