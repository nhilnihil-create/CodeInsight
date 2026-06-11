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

    int K;
    cin >> K;
    vector<int> A(K);
    for (int i = 0; i < K; ++i)
        cin >> A[i];

    bool isok = true;
    ll mi = 2, ma = 2;
    for (int i = K - 1; i >= 0; --i) {
        ll nmin = (mi + A[i] - 1) / A[i] * A[i];
        ll nmax = ma / A[i] * A[i] + A[i] - 1;
        mi = nmin, ma = nmax;
        if (mi > ma) {
            isok = false;
            break;
        }
    }

    if (isok)
        cout << mi << " " << ma << endl;
    else
        cout << -1 << endl;
    return 0;
}
