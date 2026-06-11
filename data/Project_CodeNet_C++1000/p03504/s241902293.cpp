#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

typedef pair<double, int> P;

int main() {
    int N, C;
    cin >> N >> C;
    vector<vector<P>> A(C, vector<P>());
    rep(i, N) {
        int s, t, c;
        cin >> s >> t >> c;
        c--;
        A[c].push_back(make_pair(s, t));
    }

    vector<vector<P>> B(C, vector<P>());
    rep(c, C) {
        sort(A[c].begin(), A[c].end());
        rep(i, A[c].size()) {
            if (i == 0 || B[c].back().second != A[c][i].first) {
                B[c].push_back(make_pair(A[c][i].first, A[c][i].second));
            } else {
                B[c].back().second = A[c][i].second;
            }
        }
    }

    vector<P> ev;
    rep(c, C) {
        rep(i, B[c].size()) {
            ev.push_back(make_pair(B[c][i].first - 0.5, 1));
            ev.push_back(make_pair(B[c][i].second, -1));
        }
    }
    sort(ev.begin(), ev.end());

    int ans = 0;
    int tmp = 0;
    for (auto e: ev) {
        if (e.second == 1) {
            tmp++;
            chmax(ans, tmp);
        } else {
            tmp--;
        }
    }
    cout << ans << endl;
}