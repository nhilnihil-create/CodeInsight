#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int sum = A + B + C;
    int maxv = max(A, max(B, C));

    if ((maxv * 3) % 2 == sum % 2) {
        cout << (maxv * 3 - sum) / 2 << endl;
    } else {
        cout << ((maxv + 1) * 3 - sum) / 2 << endl;
    }
}