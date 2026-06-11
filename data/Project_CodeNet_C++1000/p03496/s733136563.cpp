#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

typedef pair<int, int> P;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    int m_i = 0;
    rep(i, N) {
        if (abs(a[m_i]) < abs(a[i])) m_i = i;
    }

    vector<P> ans;
    rep(i, N) {
        if (m_i == i) continue;
        ans.push_back(make_pair(m_i + 1, i + 1));
    }

    if (a[m_i] > 0) {
        rep(i, N - 1) ans.push_back(make_pair(i + 1, i + 2));
    } else {
        for (int i = N - 1; i > 0; i--) ans.push_back(make_pair(i + 1, i));
    }

    cout << ans.size() << endl;
    rep(i, ans.size()) cout << ans[i].first << " " << ans[i].second << endl;
}