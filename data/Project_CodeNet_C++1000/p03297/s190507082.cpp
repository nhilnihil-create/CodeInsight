#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pdd = pair<double, double>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int query = 0; query < T; ++query) {
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
        if (D < B || A < B) {
            cout << "No\n";
            continue;
        }
        if (B <= C) {
            cout << "Yes\n";
            continue;
        }

        A %= B, D %= B;
        ll g = gcd(B, D);
        ll BB = B / g, DD = D / g, CC = C - A;
        if (CC < 0)
            CC += B;
        ll tmp = CC / g + 1;
        tmp *= g;
        if ((A + tmp) % B > C)
            cout << "No\n";
        else
            cout << "Yes\n";
    }

    return 0;
}
