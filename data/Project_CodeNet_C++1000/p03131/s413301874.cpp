#include <bits/stdc++.h>
using namespace std;
#define BE(x) (x).begin(), (x).end()

int main() {
    long long k, a, b;
    cin >> k >> a >> b;

    if (a+2 >= b || k < a+1) cout << 1 + k << endl;
    else {
        long long x = k-a+1;
        long long y = x/2;
        cout << y*b - (y-1)*a + x%2 << endl;
    }
}