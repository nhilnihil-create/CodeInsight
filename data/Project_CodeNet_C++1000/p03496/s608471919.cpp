#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> a(N);
    int ma = -1e9, mi = 1e9, maidx, miidx;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        if (ma < a[i])
            ma = a[i], maidx = i;
        if (mi > a[i])
            mi = a[i], miidx = i;
    }

    vector<pii> ans;
    int tmp = (abs(ma) > abs(mi) ? ma : mi);
    if ((ll)ma * mi < 0) {
        int idx = (abs(ma) > abs(mi) ? maidx : miidx);
        for (int i = 0; i < N; ++i) {
            if ((ll)tmp * a[i] < 0) {
                ans.push_back({idx, i});
                a[i] += tmp;
            }
        }
    }

    if (tmp >= 0)
        for (int i = 1; i < N; ++i)
            ans.push_back({i - 1, i});
    else
        for (int i = N - 2; i >= 0; --i)
            ans.push_back({i + 1, i});

    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i.first + 1 << " " << i.second + 1 << endl;

    return 0;
}
