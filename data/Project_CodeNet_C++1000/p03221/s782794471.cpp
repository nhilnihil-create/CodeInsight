#include <bits/stdc++.h>
using namespace std;
string to_id(int num) {
    string s = to_string(num);
    reverse(s.begin(), s.end());
    while (s.size() < 6) s += '0';
    reverse(s.begin(), s.end());
    return s;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cities(n+10, vector<int>());
    vector<int> year(m), pre(m);
    for (int i = 0; i < m; i++) {
        int p, y;
        cin >> p >> y;
        cities[p].push_back(y);
        year[i] = y, pre[i] = p;
    }
    for (int i = 0; i < n+10; i++) sort(cities[i].begin(), cities[i].end());
    for (int i = 0; i < m; i++) {
        cout << to_id(pre[i]);
        cout << to_id(lower_bound(cities[pre[i]].begin(), cities[pre[i]].end(), year[i]) - cities[pre[i]].begin() + 1);
        cout << endl;
    }
    return 0;
}