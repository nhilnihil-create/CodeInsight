#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a, b, k;
    cin >> a >> b >> k;
    for (int i = a; i <= b; i++) {
        if (i <= a + k - 1 || b - k + 1 <= i) {
            cout << i << endl;
        }
    }
    return 0;
}