#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long l0 = 2, l1 = 1, tmp;
    for (int i = 1; i < n; i++) {
        tmp = l1;
        l1 = l0 + tmp;
        l0 = tmp;
    }

    cout << l1 << endl;

    return 0;
}
