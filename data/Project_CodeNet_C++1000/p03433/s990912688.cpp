#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n >> a;
    if (n < 1 || n > 10000 || a < 0 || a > 1000) {
        cout << "No" << endl;
    } else if (n % 500 <= a) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}