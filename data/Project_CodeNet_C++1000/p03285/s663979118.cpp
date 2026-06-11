#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll n; cin >> n;
    for (int i = 0; i < 100; i += 4) {
        for (int j = 0; j < 100; j += 7) {
            if (i + j > n) continue;
            if (i + j == n) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}