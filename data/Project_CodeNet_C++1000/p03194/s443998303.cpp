#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, P;
    cin >> N >> P;

    if (N == 1) { 
        cout << P << endl;
    } else {
        int ans = 1;
        for (int i = 2; i <= sqrt(pow(10, 12)); i++) {
             ll factor = pow(i, N);
             if (P % factor == 0) ans = i;
        }
        cout << ans << endl;
    }
}