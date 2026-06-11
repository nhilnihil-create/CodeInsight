#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define rep(i, a, n) for (int i = a; i < n; ++i)

int main() {
    int d, n;
    cin >> d >> n;

    if (n == 100) n++;
    int ans = 1;
    rep(i, 0, d) ans *= 100;
    cout << ans * n << endl;

    return 0;
}
