#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

const int MXN = 2e5;
vector<pair<int, int>> city[MXN + 1];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    int c = 1;
    unordered_set<int> pre;
    for (int i=0; i<m; ++i) {
        int p, y; cin >> p >> y;
        pre.insert(p);
        city[p].PB(MP(y, c));
        c++;
    }
    vector<pair<int, string>> ans;
    for (auto i : pre) {
        vector<pair<int, int>> pi = city[i];
        sort(pi.begin(), pi.end());
        for (int j = 0; j < pi.size(); ++j) {
            string s1(6 - to_string(i).size(), '0'), s2(6 - to_string(j + 1).size(), '0');
            s1 += to_string(i);
            s2 += to_string(j + 1);
            ans.PB(MP(pi[j].second, s1 + s2));
        }
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans) {
        cout << i.second << "\n";
    }
}