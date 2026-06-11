#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using Graph = vector<vector<bool>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;
    A--, B--;

    printf("%d %d\n", 100, 100);

    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 100; ++j) {
            bool iswhite = (A > 0) & !((i | j) & 1);
            A -= iswhite;
            putchar(iswhite ? '.' : '#');
        }
        putchar('\n');
    }

    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 100; ++j) {
            bool isblack = (B > 0) & (i & j & 1);
            B -= isblack;
            putchar(isblack ? '#' : '.');
        }
        putchar('\n');
    }
    return 0;
}
