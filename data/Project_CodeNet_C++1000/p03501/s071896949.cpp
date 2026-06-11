#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    cout << min(n * a, b) << endl;
    return 0;
}