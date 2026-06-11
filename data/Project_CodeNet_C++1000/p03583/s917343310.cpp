#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll N;   cin >> N;
    for (ll h = 1; h <= 3500; h++) {
        for (ll n = 1; n <= 3500; n++) {
            ll k = N*h*n, l = 4*h*n - N*n - N*h;
            if (l > 0 && k % l == 0) {
                cout << h << " " << n << " " << k/l << endl;
                return 0;
            }
        }
    }
}