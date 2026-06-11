#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<pair<pair<string, int>, int>> v;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int p;
        cin >> p;
        p = -p;
        v.push_back(make_pair(make_pair(s, p), i));
    }
    sort(v.begin(), v.end());
    for (auto &&i : v) {
        cout << i.second << endl;
    }

    return 0;
}