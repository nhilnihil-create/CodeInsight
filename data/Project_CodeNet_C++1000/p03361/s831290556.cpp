#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

const string YES = "Yes";
const string NO = "No";

void solve(long long H, long long W, std::vector<std::string> s) {
    vector<pair<ll, ll>> dir{pair<ll, ll>(-1, 0), pair<ll, ll>(1, 0), pair<ll, ll>(0, -1), pair<ll, ll>(0, 1)};
    rep(i, H) {
        rep(j, W) {
            if (s[i][j] == '#') {
                bool ok = false;
                rep(k, 4) {
                    ll tmpi = i + dir[k].first;
                    ll tmpj = j + dir[k].second;
                    if (!(tmpi < 0 || tmpi > H - 1 || tmpj < 0 || tmpj > W - 1)) {
                        if (s[tmpi][tmpj] == '#') {
                            ok = true;
                        }
                    }
                }
                if (!ok) {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return;
}

int main() {
    long long H;
    scanf("%lld", &H);
    long long W;
    scanf("%lld", &W);
    std::vector<std::string> s(H);
    for (int i = 0; i < H; i++) {
        std::cin >> s[i];
    }
    solve(H, W, std::move(s));
    return 0;
}
