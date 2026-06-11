#include <bits/stdc++.h>
using namespace std;

signed main () {
    string s;
    cin >> s;
    int n = int(s.size()), k;
    cin >> k;
    set < string > used;
    vector < string > srt;
    for (int i = 0; i < n; ++i) {
        string cur = "";
        for (int j = i; j < min(i + k, n); ++j) {
            cur += s[j];
            if (used.find(cur) == used.end()) {
                srt.push_back(cur);
                used.insert(cur);
            }
        }
    }
    sort(srt.begin(), srt.end());
    cout << srt[k - 1] << '\n';
}
