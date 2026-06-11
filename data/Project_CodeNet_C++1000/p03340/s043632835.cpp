#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using Graph = vector<vector<int>>;
const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    int exor = 0;
    ll ans = 0;
    for (int l = 0, r = 0; l < N; ++l) {
        int cnt = 0;
        while (r < N && !(exor & A[r])) {
            exor ^= A[r];
            cnt++;
            r++;
        }
        if (cnt) {
            ll tmp = r - l;
            ans += tmp * (tmp + 1) / 2;
            tmp -= cnt;
            ans -= tmp * (tmp + 1) / 2;
        }
        exor ^= A[l];
    }

    cout << ans << endl;

    return 0;
}
