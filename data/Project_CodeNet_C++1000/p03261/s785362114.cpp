#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main() {
    fastio;
    int n;
    cin >> n;
    set<string> s;
    vector<pair<char, char>> v;
    for (int i = 0; i < n; ++i) {
        string in;
        cin >> in;
        s.insert(in);
        v.push_back({ in.front(), in.back() });
    }

    if (s.size() != n) {
        cout << "No";
        return 0;
    }
    else {
        for (int i = 1; i < n; ++i) {
            if (v[i].first != v[i - 1].second) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}