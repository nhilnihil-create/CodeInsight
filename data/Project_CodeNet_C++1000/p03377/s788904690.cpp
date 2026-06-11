#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, x; cin >> a >> b >> x;
    bool ans = true;
    if (a>x)
        ans = false;
    if (a+b<x)
        ans = false;
    cout << (ans ? "YES": "NO") << endl;
}