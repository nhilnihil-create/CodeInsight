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
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    unordered_map<int, int> mp;
    mp[0] = 1;

    ll ans = 0;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        (sum += A) %= M;
        ans += (mp[sum]++);
    }

    cout << ans << endl;
    return 0;
}
