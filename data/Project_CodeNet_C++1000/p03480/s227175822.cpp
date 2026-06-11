#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
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

    string S;
    cin >> S;
	//at most max(n,n-k) flip find min of this
    int N = S.length();
    int ans = N;
    for (int i = 0; i < N - 1; ++i) {
        if (S[i] != S[i + 1])
            ans = min(ans, max(i + 1, N - i - 1));
    }

    cout << ans << endl;
    return 0;
}
