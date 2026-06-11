#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int k;
    cin >> k;
    int mx = max({a, b, c});
    int ans = a + b + c - mx;
    for (int i = 0; i < k; ++i) mx *= 2;
    cout << ans + mx << endl;
}
