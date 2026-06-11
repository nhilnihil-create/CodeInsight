#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;



int main() {
    int a, b, c; cin >> a >> b >> c;
    if (a == b) cout << c << endl;
    else if (b == c) cout << a << endl;
    else cout << b << endl;
}