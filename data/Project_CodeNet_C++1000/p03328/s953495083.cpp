#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
using namespace std;
using ll = long long;

int main() {
    int a, b;
    cin >> a >> b;
    int tmp = b - a;
    cout << (1 + tmp)*tmp/2 - b << endl;
    return 0;
}