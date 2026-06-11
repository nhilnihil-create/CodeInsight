// ソートがボトルネックの貪欲だった、、、
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> ab(M);
    for (int i = 0; i < M; ++i) {
        cin >> ab[i].first >> ab[i].second;
    }
    auto cmp = [](pair<int, int> &a, pair<int, int> &b) -> bool { return a.second < b.second; };
    sort(ab.begin(), ab.end(), cmp);
    int prev = -1;
    int res = 0;
    for (auto p : ab) {
        //cout << p.first << " : " << p.second << endl;
        if (p.first <= prev) continue;
        ++res;
        prev = p.second - 1;
    }
    cout << res << endl;
    return 0;
}