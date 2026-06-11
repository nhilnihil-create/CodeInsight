#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int r;
    cin >> r;
    if (r < 1200)
        cout << "ABC";
    else if (r >= 1200 && r < 2800)
        cout << "ARC";
    else
        cout << "AGC";
    return 0;
}