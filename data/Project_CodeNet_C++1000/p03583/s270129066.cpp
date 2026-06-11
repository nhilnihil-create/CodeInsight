#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int INF = 101234567;

int main() {
    ll N;
    cin >> N;

    ll a = 2;
    ll b = 3;

    for (ll h = 1; h <= 3500; h++) {
        for (ll n = 1; n <= 3500; n++) {
            ll v1, v2;
            v1 = N*h*n;
            v2 = 4*h*n - N*n - h*N;
            if (v1 > 0 && v2 > 0 && v1%v2 == 0) {
                ll w = v1/v2;
                cout << h << " " << n << " " << w << endl;
                return 0;
            }
        }
    }
}
