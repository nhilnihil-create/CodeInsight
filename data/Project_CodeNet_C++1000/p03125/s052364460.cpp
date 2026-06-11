#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int a, b;
    cin >> a >> b;
    if (b % a == 0)
        cout << a + b << endl;
    else
        cout << b - a << endl;

    return 0;
}