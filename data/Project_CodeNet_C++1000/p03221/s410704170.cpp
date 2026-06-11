#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> P;
    vector<vector<int>> City(n+1);
    for(int i = 0; i < m; i++) {
        int p, y;
        cin >> p >> y;
        City[p].push_back(y);
        P.push_back(make_pair(p, y));
    }
    for(int i = 1; i <= n; i++) {
        sort(City[i].begin(), City[i].end());
    }
    for(auto au : P) {
        string ans = "";
        string a = to_string(au.first);
        for(int i = 0; i < (6-a.size()); i++) {
            ans += '0';
        }
        ans += a;
        int it = lower_bound(City[au.first].begin(), City[au.first].end(), au.second) - City[au.first].begin();
        it++;
        string b = to_string(it);
        for(int i = 0; i < (6-b.size()); i++) {
            ans += '0';
        }
        ans += b;
        cout << ans << "\n";
    }
    return 0;
}