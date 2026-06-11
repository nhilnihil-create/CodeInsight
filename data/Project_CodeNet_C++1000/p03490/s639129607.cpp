#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s;
    int x, y, f = 0, cnt = 0;
    cin >> s >> x >> y;
    int n = int(s.size());
    vector< vector<int> > d(2);
    for (int i = 0; i < n; ++i) switch (s.at(i)) {
        case 'F': ++cnt; break;
        case 'T': d.at(f).push_back(cnt); f ^= 1; cnt = 0; break;
    }
    d.at(f).push_back(cnt);
    vector< vector< vector<bool> > > dp(2);
    for (int i = 0; i < 2; ++i) dp.at(i) = vector< vector<bool> >(d.at(i).size() + 1, vector<bool>(n * 2 + 1)), dp.at(i).at(0).at(n) = 1;
    for (int i = 0; i < 2; ++i) for (int j = 0; j < int(d.at(i).size()); ++j) {
        if ((i | j) == 0) dp.at(0).at(1).at(n + d.at(0).at(0)) = 1;
        else for (int k = 0; k <= 2 * n; ++k) if (dp.at(i).at(j).at(k)) dp.at(i).at(j + 1).at(k + d.at(i).at(j)) = 1, dp.at(i).at(j + 1).at(k - d.at(i).at(j)) = 1;
    }
    cout << (dp.at(0).back().at(n + x) && dp.at(1).back().at(n + y) ? "Yes" : "No") << '\n';
    return 0;
}
