#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    if (N & 1)
        cout << ((N - 1) * (N - 3) >> 1) + N - 1 << '\n';
    else
        cout << (N * (N - 2) >> 1) << '\n';

    for (int i = 1; i < N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (j == N - i + !(N & 1))
                continue;
            cout << i << ' ' << j << '\n';
        }
    }

    return 0;
}
