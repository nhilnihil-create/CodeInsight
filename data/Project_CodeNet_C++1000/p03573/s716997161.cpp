#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (a[0] == a[1]) cout << a[2] << '\n';
    else cout << a[0] << '\n';
}