#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <typename T> using V = vector<T>;
template <typename T> using VV = V<V<T>>;

int n;
V<int> a;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    a = V<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x = *max_element(begin(a), end(a));
    int y = -1;

    auto shift = [&](int x, int y) {
        if (x % 2 == 0 || y < x/2) return abs(x/2-y);
        return abs((x+1)/2-y);
    };

    for (int i = 0; i < n; i++) {
        if (a[i] == x) continue;
        if (shift(x, a[i]) < shift(x, y)) {
            y = a[i];
        }
    }
    printf("%d %d\n", x, y);
    return 0;
}