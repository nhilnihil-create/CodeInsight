#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N, M, tmp;
    cin >> N >> M;
    vector<int> k(M), p(M);
    vector<vector<int>> s(M);
    rep(i,M) {
        cin >> k.at(i);
        rep(j,k.at(i)) {
            cin >> tmp;
            s.at(i).push_back(tmp);
        }
    }
    rep(i,M) cin >> p.at(i);

    int ans = 0;
    for (int bit = 0; bit < (1<<N); ++bit) {
        bool ok = true;
        rep(i,M) {
            int cnt = 0;
            rep(j,k.at(i)) if (bit & (1<<(s.at(i).at(j)-1))) ++cnt;
            if (cnt % 2 != p.at(i)) {
                ok = false;
                break;
            }
        }
        if (ok) ++ans;
    }
    cout << ans << endl;
}

