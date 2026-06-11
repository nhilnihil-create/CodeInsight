#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    if (n % 2 == 0)
        cout << n << endl;
    else
        cout << 2 * n << endl;
    return 0;
}