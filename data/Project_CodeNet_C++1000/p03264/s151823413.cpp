#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int k, l;
    cin >> k;
    int g = k / 2;
    if (k % 2 == 1)
        l = g + 1;
    else
        l = g;

    cout << g * l << endl;

    return 0;
}