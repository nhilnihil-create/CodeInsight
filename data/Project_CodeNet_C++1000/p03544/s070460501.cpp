#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    long long a = 2, b = 1, c = 1;
    for (int i = 2; i <= n; i++) {
        c = b + a;
        a = b;
        b = c;
    }
    cout << c << endl;
    return 0;
}