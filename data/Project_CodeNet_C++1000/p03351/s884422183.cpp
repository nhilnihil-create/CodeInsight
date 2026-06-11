#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (abs(a - b) <= d && abs(b - c) <= d)
        cout << "Yes" << endl;
    else if (abs(a - c) <= d)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}