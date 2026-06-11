#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    vector<int> cnt(3, 0);
    for (char c : s) {
        cnt[c - 'a']++;
    }
    sort(cnt.rbegin(), cnt.rend());
    cnt[0] -= cnt[2];
    cnt[1] -= cnt[2];
    if ((cnt[0] == 0 && cnt[1] == 0) || (cnt[0] == 1 && cnt[1] == 0) || (cnt[0] == 1 && cnt[1] == 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}