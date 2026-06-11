
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, a, b, c, d, e;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> a >> b >> c >> d >> e;
    b = min(a, b);
    c = min(b, c);
    d = min(c, d);
    e = min(d, e);
    ll res = (n + e - 1) / e + 4;
    cout << res << endl;

    return 0;
}

