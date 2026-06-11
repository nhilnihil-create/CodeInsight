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

    int N;
    cin >> N;
    vector<vector<char>> S(N, vector<char>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> S[i][j];

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        {
            bool flag = true;
            for (int j = 0; j < N && flag; ++j) {
                for (int k = j + 1; k < N && flag; ++k) {
                    int ktmp = k - i, jtmp = j - i;
                    if (ktmp < 0)
                        ktmp += N;
                    if (jtmp < 0)
                        jtmp += N;
                    if (S[j][ktmp] != S[k][jtmp])
                        flag = false;
                }
            }
            if (flag)
                ans += N - i;
        }

        if (i != 0) {
            bool flag = true;
            for (int j = 0; j < N && flag; ++j) {
                for (int k = j + 1; k < N && flag; ++k) {
                    int ktmp = k - i, jtmp = j - i;
                    if (ktmp < 0)
                        ktmp += N;
                    if (jtmp < 0)
                        jtmp += N;
                    if (S[jtmp][k] != S[ktmp][j])
                        flag = false;
                }
            }
            if (flag)
                ans += N - i;
        }
    }

    cout << ans << endl;

    return 0;
}
