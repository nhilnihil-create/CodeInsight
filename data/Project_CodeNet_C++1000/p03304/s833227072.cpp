#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(15);
    cout << fixed;
    ll d = 0ll, n = 0ll, m = 0ll;
    cin >> n >> m >> d;
    --m;
    if (d==0ll) {
        cout << (long double)(m)/n;
    } else {
        cout << (long double)(2ll*m*(n-d))/(1ll*n*n);
    }
    cout << endl;
}
