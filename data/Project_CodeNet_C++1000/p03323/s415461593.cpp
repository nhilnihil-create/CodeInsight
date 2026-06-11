#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int a, b;
    cin >> a >> b;
    if (a <= 8 && b <= 8)
        cout << "Yay!" << endl;
    else
        cout << ":(" << endl;
    return 0;
}