#include <bits/stdc++.h>
using namespace std;

int main() {
    int s;
    cin >> s;

    int cnt = 1;
    while(s != 4) {
        if (s <= 2) break;
        if (s % 2 == 0) {
            s /= 2;
        } else {
            s = 3 * s + 1;
        }
        cnt++;
    }

    cout << cnt + 3 << endl;

    return 0;
}
