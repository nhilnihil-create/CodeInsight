#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a < c && c < b) || (b < c && c < a)) {
        puts("Yes");
    } else {
        puts("No");
    }
}
