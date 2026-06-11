#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using piii = pair<int, pair<int, int>>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int M, K;
    cin >> M >> K;

    int ma = 1 << M;
    vector<int> ans;
    vector<bool> isused(ma);
    for (int i = 0; i < ma; ++i) {
        if (isused[i])
            continue;
        int tmp = K ^ i;
        if (tmp < ma) {
            ans.push_back(i);
            ans.push_back(tmp);
            isused[i] = isused[tmp] = true;
        }
    }

    if (K == 0) {
        for (int i = 0; i < ma * 2; ++i)
            cout << ans[i] << " ";
        cout << endl;
        return 0;
    }

    if (ma != ans.size() || ((ans.size() >> 1) & 1)) {
        cout << -1 << '\n';
        return 0;
    }
    
    for (int i = 0; i < ma; i += 2)
        cout << ans[i + 1] << " " << ans[i] << " ";
    for (int i = 0; i < ma; ++i)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
