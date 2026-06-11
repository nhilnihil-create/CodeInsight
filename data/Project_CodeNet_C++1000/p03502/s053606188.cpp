#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int now = n;
    int count = 0;
    while (now > 0) {
        count += now % 10;
        now /= 10;
    }
    if (n % count == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
