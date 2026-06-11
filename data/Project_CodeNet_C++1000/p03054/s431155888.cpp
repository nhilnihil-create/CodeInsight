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

    int H, W, N, sr, sc;
    string S, T;
    cin >> H >> W >> N >> sr >> sc >> S >> T;

    auto func = [&](char mi, char ma, int pos, int siz) -> bool {
        int posmi = pos, posma = pos;
        for (int i = 0; i < N; ++i) {
            if (S[i] == ma)
                posma++;
            else if (S[i] == mi)
                posmi--;
            if (posma > siz)
                return true;
            if (posmi < 1)
                return true;
            if (T[i] == ma)
                posmi = min(posmi + 1, siz);
            else if (T[i] == mi)
                posma = max(posma - 1, 1);
            if (posma > siz)
                return true;
            if (posmi < 1)
                return true;
        }
        return false;
    };

    bool res = false;
    res |= func('U', 'D', sr, H);
    res |= func('L', 'R', sc, W);

    cout << (res ? "NO" : "YES") << endl;

    return 0;
}
