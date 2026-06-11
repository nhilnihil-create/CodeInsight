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

    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    vector<ll> b;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        ll tmp = 0;
        for (int j = i; j >= 0; --j) {
            tmp += a[j];
            b.push_back(tmp);
        }
    }

    ll ans = 0;
    int siz = b.size();
    for (int i = 39; i >= 0; --i) {
        int cnt = 0;
        ans |= (1LL << i);
        for (int j = 0; j < siz; ++j)
            if ((b[j] & ans) == ans)
                cnt++;
        if (cnt < K)
            ans &= ~(1LL << i);
    }

    cout << ans << endl;

    return 0;
}
