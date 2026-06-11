#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int keta(int &n) {
    string s = to_string(n);
    return s.size();
}

int main() {
    int N, M, tmp1, tmp2;
    cin >> N >> M;
    vector<vector<P>> p(N);
    rep(i, M) {
        cin >> tmp1 >> tmp2;
        p.at(tmp1 - 1).push_back(make_pair(tmp2, i));
    }
    rep(i, N) if (!p.at(i).empty()) sort(p.at(i).begin(), p.at(i).end());
    vector<P> ans(M);
    rep(i, N) if (!p.at(i).empty()) {
        int j = 0;
        for (auto x : p.at(i)) {
            ans.at(x.second) = make_pair(i + 1, j + 1);
            ++j;
        }
    }
    for (auto x : ans) {
        string res;
        rep(i, 6 - keta(x.first)) res.push_back('0');
        res = res + to_string(x.first);
        rep(i, 6 - keta(x.second)) res.push_back('0');
        res = res + to_string(x.second);
        cout << res << endl;
    }
}
