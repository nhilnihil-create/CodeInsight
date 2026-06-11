//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<P> p(m);
    vector<vector<P>> ans(n);
    rep(i, m) {
        cin >> p[i].first >> p[i].second;
        ans[p[i].first-1].push_back(P(p[i].second, i));
    }

    rep(i, n) {
        sort(ans[i].begin(),ans[i].end());
    }

    rep(i, n) {
        rep(j, ans[i].size()) {
            p[ans[i][j].second].second = j + 1;
        }
    }

    rep(i,m) {
        cout << setw(6) << setfill('0');
        cout << p[i].first;
        cout << setw(6) << setfill('0');
        cout << p[i].second << endl;;
    }
    return 0;
}
