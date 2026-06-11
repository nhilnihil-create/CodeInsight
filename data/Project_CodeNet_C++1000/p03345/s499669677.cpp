#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    ll a, b, c, k;
    cin >> a >> b >> c >> k;

    // a[i] = b[i-1] + c[i-1]
    // b[i] = c[i-1] + a[i-1]
    // c[i] = a[i-1] + b[i-1]
    // a[i]-b[i] = b[i-1]-a[i-1]
    cout << (a-b)*(k&1?-1:1) << endl;
}
