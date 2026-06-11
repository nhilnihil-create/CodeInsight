#include <bits/stdc++.h>

using namespace std;

int main() {
    int s;
    cin >> s;

    int r = 0;

    for (int i = 0; i < 3; i++) {
        if (s % 10 == 1) r++;
        s /= 10;
    }

    cout << r << endl;

    return 0;
}
