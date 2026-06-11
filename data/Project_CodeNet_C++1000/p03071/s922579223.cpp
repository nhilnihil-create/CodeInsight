#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a, b;
    cin >> a >> b;
    if (a>b) cout << a+a-1;
    else if (b>a) cout << b+b-1;
    else cout << a+b;
    return 0;
}