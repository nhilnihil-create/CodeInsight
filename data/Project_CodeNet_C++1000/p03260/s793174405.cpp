#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int a, b;
    cin >> a >> b;
    if ((a * b) % 2 == 0)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}