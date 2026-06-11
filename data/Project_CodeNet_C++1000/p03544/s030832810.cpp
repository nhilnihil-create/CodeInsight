#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long m;

    if (n == 0)
        m = 2;
    else if (n == 1)
        m = 1;
    else {
        long long a = 2, b = 1;
        for (int i = 2; i <= n; i++) {
            m = a + b;
            a = b;
            b = m;
        }
    }

    cout << m << endl;
}