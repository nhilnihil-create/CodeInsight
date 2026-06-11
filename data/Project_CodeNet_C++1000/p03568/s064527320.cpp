#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];

    int all = pow(3, n);
    int bad = 1;
    rep(i, n) if (a[i] % 2 == 0) bad *= 2;

    cout << all - bad << endl;
    return 0;
}