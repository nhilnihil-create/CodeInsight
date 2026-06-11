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
using matrix = vector<vector<uint>>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            char c;
            cin >> c;
            if (i == j)
                cout << c;
        }
    }
    cout << endl;

    return 0;
}
