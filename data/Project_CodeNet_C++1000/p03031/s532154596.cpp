#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N, M;
    cin >> N >> M;

    vec<int> k(M);
    vec<vec<int>> s(M, vec<int>());
    rep(i, M) {
        cin >> k[i];
        rep(j, k[i]) {
            int sj;
            cin >> sj;
            --sj;
            s[i].push_back(sj);
        }
    }

    vec<int> p(M);
    rep(i, M) cin >> p[i];

    int ans = 0;
    rep(i, 1 << N) {
        int light = 0;
        rep(j, M) {
            int val = 0;
            for (auto e : s[j])
                if(i & (1 << e)) ++val;
            if(val%2 == p[j]) ++light;
        }
        if(light == M) ++ans;
    }
    cout << ans << endl;
}
