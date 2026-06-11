#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n, a, b; cin >> n >> a >> b;

    if (b - a == 1) {
        puts("Borys");
        return 0;
    }

    while (b - a > 1) {
        a++;
        if (b - a == 1) {
            puts("Alice");
            return 0;
        }

        b--;
        if (b - a == 1) {
            puts("Borys");
            return 0;
        }
    }
}