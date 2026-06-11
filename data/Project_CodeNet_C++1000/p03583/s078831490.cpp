#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    cin >> N;
    for (ll h = 1; h <= 3500; h++) {
        for (ll n = 1; n <= 3500; n++) {
            ll z = 4*h*n - N*n - N*h;
            if (z > 0 && N*h*n % z == 0) {
                cout << h << " " << n << " " << N*h*n / z << endl;
                return 0;
            }
        }
    }
}