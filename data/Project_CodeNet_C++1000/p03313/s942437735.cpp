#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

int main()
{ _
    int n; cin >> n;

    vector a(1 << n, 0);
    for (int i = 0; i < (1 << n); ++i) cin >> a[i];

    vector S(1 << n, pair(0, 0));
    for (int i = 0; i < (1 << n); ++i)
        S[i].first = a[i];

    auto insert = [](pair<int, int>& S, pair<int, int> T)
    {
        int x = T.first, y = T.second;

        if (x > S.second) S.second = x;
        if (S.first < S.second) swap(S.first, S.second);

        if (y > S.second) S.second = y;
        if (S.first < S.second) swap(S.first, S.second);
    };

    for (int k = 0; k < n; ++k)
        for (int x = 0; x < (1 << n); ++x)
            if ((x >> k & 1) == 0) insert(S[x | (1 << k)], S[x]);

    int ans = 0;
    for (int i = 1; i < (1 << n); ++i)
    {
        ans = max(ans, S[i].first + S[i].second);
        cout << ans << endl;
    }

    exit(0);
}

