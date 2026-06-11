#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int d = n % 10;
    n /= 10;
    int c = n % 10;
    n /= 10;
    int b = n % 10;
    n /= 10;
    int a = n % 10;

    if ((a == b && b == c) || (b == c && c == d)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}