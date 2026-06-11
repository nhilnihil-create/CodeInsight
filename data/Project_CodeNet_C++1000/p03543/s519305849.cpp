#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int tmp, c = 1;
    tmp = n % 10;
    n /= 10;
    for (int i = 0; i < 3; i++) {
        if (tmp == n % 10) {
            c++;
        } else {
            tmp = n % 10;
            c = 1;
        }
        if (c == 3) break;
        n /= 10;
    }

    if (c == 3) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

