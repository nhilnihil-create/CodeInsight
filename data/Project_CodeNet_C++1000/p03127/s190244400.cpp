#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, gcd;
    cin >> n >> gcd;
    n--;
    while (n--) {
        int a;
        cin >> a;
        gcd = __gcd(gcd, a);
    }
    cout << gcd << endl;
}

