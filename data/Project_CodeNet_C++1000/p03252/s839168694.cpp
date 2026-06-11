#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define nl '\n'
#define f(i, n) for (int i = 0; i < n; ++i)

using namespace std;
void solve() {
    string s, t;
    cin >> s >> t;
    if (s.size() != t.size()) {
        cout << "No" << nl;
        return;
    }
    vector<int> one(26, 0);
    vector<int> two(26, 0);
    vector<int> three(26, 0);
    for (char e : s) {
        one[e - 'a']++;
        three[e - 'a']++;
    }
    for (char e : t) {
        two[e - 'a']++;
    }
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());
    bool okay = true;
    for (int i = 0; i < 26; ++i) {
        if (one[i] != two[i]) {
            okay = false;
            break;
        }
    }

    cout << (okay ? "Yes" : "No") << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}