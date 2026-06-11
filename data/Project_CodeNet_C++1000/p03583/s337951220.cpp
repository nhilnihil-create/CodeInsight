#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using ull = unsigned long long;
using ll = long long;
using namespace std;

bool is_int(double x) {
    return abs(x - int(x)) < pow(0.1, 8);
}
int main(void) {
    ll n;
    cin >> n;
    const int LIM = 3500;
    for (int i = 1; i <= LIM; ++i) {
        for (int j = 1; j <= LIM; ++j) {
            const ll d = n * i * j;
            const ll m = 4LL * i * j - i * n - j * n;
            if (m <= 0) {
                continue;
            }

            if (d % m != 0) {
                continue;
            }

            ll u = d/m;

            if (0 < u && u <= LIM) {
                printf("%d %d %lld\n", i, j, u);
                return 0;
            }
            // double a = double(d)/m;
            // if (a > 0 && is_int(a)) { 
            //     cout << i << " " << j << " " << int(a) << endl;
            //     return 0;
            // }
            // if (m != 0 && (n * i * j) % m == 0) {
                // int u = (n * i * j) / m;
                // if (u > 0 && u <= LIM) {
                    // cout << i << " " << j << " " << u << endl;
                    // return 0;
                // }
        }
    }

    return 0;
}