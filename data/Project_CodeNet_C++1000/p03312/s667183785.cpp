#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif

    int N;
    cin >> N;
    Vl A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    Vl csum(N + 1);
    for (int i = 0; i < N; i++) {
        csum[i + 1] = csum[i] + A[i];
    }

    ll ans = L_INF;
    int l = 1, r = 3;
    for (int i = 2; i < N - 1; i++) {
        while (l < i && csum[l] - csum[0] < csum[i] - csum[l]) ++l;
        --l;
        while (r < N && csum[r] - csum[i] < csum[N] - csum[r]) ++r;
        --r;

        int l_tmp = l, r_tmp = r;
        if (l_tmp < i - 1) {
            ll t1 = abs((csum[i] - csum[l_tmp]) - (csum[l_tmp] - csum[0]));
            ll t2 = abs((csum[i] - csum[l_tmp + 1]) - (csum[l_tmp + 1] - csum[0]));
            if (t1 > t2) {
                ++l_tmp;
            }
        }
        if (r_tmp < N - 1) {
            ll t1 = abs((csum[N] - csum[r_tmp]) - (csum[r_tmp] - csum[i]));
            ll t2 = abs((csum[N] - csum[r_tmp + 1]) - (csum[r_tmp + 1] - csum[i]));
            if (t1 > t2) {
                ++r_tmp;
            }
        }

        ll s1, s2, s3, s4;
        s1 = csum[l_tmp] - csum[0];
        s2 = csum[i] - csum[l_tmp];
        s3 = csum[r_tmp] - csum[i];
        s4 = csum[N] - csum[r_tmp];

        ll mn, mx;
        mn = min({s1, s2, s3, s4});
        mx = max({s1, s2, s3, s4});

        ans = min(ans, mx - mn);
    }

    cout << ans << endl;

    return 0;
}