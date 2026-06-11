#include <bits/stdc++.h>
//#include "atcoder/all"
typedef long long int ll;
using namespace std;
// using namespace atcoder;
int main() {
    int n;
    cin >> n;
    int d[8] = {2, 3, 4, 6, 8, 9, 10, 12};
    int t = n / 8;
    if (n == 3) {
        cout << 2 << " " << 5 << " " << 63;
        return 0;
    }
    if (n % 8 == 1) {
        cout << 6 << " ";
    }
    else if (n % 8 == 2) {
        cout << 6 << " " << 12 << " ";
    }
    else if (n % 8 == 3) {
        cout << 2 << " " << 4 << " " << 6 << " ";
    }
    else if (n % 8 == 4) {
        cout << 2 << " " << 3 << " " << 9 << " " << 10 << " ";
    }
    else if (n % 8 == 5) {
        cout << 2 << " " << 3 << " " << 4 << " " << 6 << " " << 9 << " ";
    }
    else if (n % 8 == 6) {
        cout << 2 << " " << 3 << " " << 4 << " " << 6 << " " << 9 << " " << 12 << " ";
    }
    else if (n % 8 == 7) {
        cout << 2 << " " << 3 << " " << 4 << " " << 6 << " " << 8 << " " << 9 << " " << 10 << " ";
    }
    else {
        cout << 2 << " " << 3 << " " << 4 << " " << 6 << " " << 8 << " " << 9 << " " << 10 << " " << 12 << " ";
        t--;
    }
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < 8; j++) {
            cout << i * 12 + d[j] << " ";
        }
    }
    return 0;
}