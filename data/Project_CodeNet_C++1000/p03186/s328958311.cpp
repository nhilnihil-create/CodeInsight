#include <bits/stdc++.h>
using namespace std;
#define vec(type) vector<type>

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    long long ans;
    if (b >= c) ans = b+c;
    else if (a+b < c) ans = a+b + b + 1;
    else ans = c + b;

    cout << ans << endl;
}