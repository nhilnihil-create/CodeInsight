#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;
    ll minim = min(min(min(min(a,b),c),d),e);
    ll res = n/minim;
    if (n%minim>0) res++;
    cout << res+4;
    return 0;
}