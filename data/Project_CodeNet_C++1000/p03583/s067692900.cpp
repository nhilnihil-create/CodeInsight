#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    lint n;
    cin >> n;

    lint a, b, c;

    for (lint i = 1; i <= 3500; i++) {
        for (lint j = 1; j <= 3500; j++) {
            lint p = (n * i * j);
            lint q = (4 * i * j - n * i - n * j);
            if (q == 0) continue;
            if (p % q == 0 && p / q > 0) {
                a = i;
                b = j;
                c = p / q;
                printf("%lld %lld %lld\n", a, b, c);
                exit(0);
            }
        }
    }
    return 0;
}