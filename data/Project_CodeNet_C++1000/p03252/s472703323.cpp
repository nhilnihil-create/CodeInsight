#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> v_s(200009, vector<int>()), v_t(200009, vector<int>());
    vector<int> used_s(26), used_t(26);

    string s, t;  cin >> s >> t;
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (used_s[s[i] - 'a'] == 0) {
            used_s[s[i] - 'a'] = cnt;
            v_s[cnt].push_back(i);
            ++cnt;
        }
        else {
            v_s[used_s[s[i] - 'a']].push_back(i);
        }
    }
    cnt = 0;
    for (int i = 0; i < t.size(); ++i) {
        if (used_t[t[i] - 'a'] == 0) {
            used_t[t[i] - 'a'] = cnt;
            v_t[cnt].push_back(i);
            ++cnt;
        }
        else {
            v_t[used_t[t[i] - 'a']].push_back(i);
        }
    }

    for (int i = 0; i < 200009; ++i) {
        if (v_s[i].size() != v_t[i].size()) {
            cout << "No" << endl;
            return 0;
        }
        for (int j = 0; j < v_s[i].size(); ++j) {
            if (v_s[i][j] != v_t[i][j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
