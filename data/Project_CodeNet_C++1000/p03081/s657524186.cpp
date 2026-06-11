#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

bool check(const string &s, const vector<pair<char, char>> &v, int x) {
    for (const auto &p : v) {
        if (s[x] == p.first) {
            x += (p.second == 'R' ? 1 : -1);
            if (x == -1)
                return true;
            if (x == s.size())
                return false;
        }
    }
    return false;
}

int get_rightmost(const string &s, const vector<pair<char, char>> &v) {
    int l = -1, r = s.size();
    while (r - l > 1) {
        int p = (l + r) >> 1;
        if (check(s, v, p))
            l = p;
        else
            r = p;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int n, m;
    cin >> n >> m >> s;

    vector<pair<char, char>> v;

    for (int i = 0; i < m; i++) {
        char a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }

    int x = get_rightmost(s, v);

    reverse(all(s));
    for (auto &p : v) {
        p.second = (p.second == 'R' ? 'L' : 'R');
    }

    int y = n - 1 - get_rightmost(s, v);

    cout << y - x - 1 << "\n";

    return 0;
}