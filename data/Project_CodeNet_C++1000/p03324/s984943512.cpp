#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, n, result;
    cin >> d >> n;
    if (n == 100) {
        result = pow(100,d) * n + pow(100,d);
    } else {
        result = pow(100,d) * n;
    }
    cout << result << endl;
}
