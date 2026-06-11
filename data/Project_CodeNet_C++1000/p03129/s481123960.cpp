#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    int n, k;
    cin >> n >> k;
    n = (n + 1) / 2;
    if (n >= k) puts("YES");
    else
        puts("NO");
}