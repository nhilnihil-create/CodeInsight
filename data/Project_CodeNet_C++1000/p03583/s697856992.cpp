#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    ll N;
    cin >> N;
    for(ll b = 1; b <= 3500; b++)
        for(ll n = b; n <= 3500; n++)
            if((4 * n * b - N * b - N * n) != 0)
                if((N * n * b) % (4 * n * b - N * b - N * n) == 0)
                    if((N * n * b) / (4 * n * b - N * b - N * n) > 0) {
                        cout << (N * n * b) / (4 * n * b - N * b - N * n) << " " << b << " " << n << "\n";
                        return 0;
                    }

    return 0;
}
