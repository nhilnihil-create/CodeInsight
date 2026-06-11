#include <bits/stdc++.h>
using namespace std;

void chmax (int &x, int a) {
    x = max(x, a);
}

signed main () {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector < int > points_beg, points_end; // whats the point, dumbass?
    if (s.front() == '0') {
        int i;
        for (i = 0; i < n; ++i) {
            if (s[i] == '1')
                break;
        }
        points_end.push_back(i);
    }
    points_beg.push_back(0);
    for (int i = 1; i < n; ++i) {
        if (s[i] == '1' && s[i - 1] == '0')
            points_beg.push_back(i);
        if (s[i] == '0' && s[i - 1] == '1')
            points_end.push_back(i);
    }
    if (s.back() == '0') 
        points_beg.push_back(points_end.back());
    points_end.push_back(n);
    int ans = 0;
    for (int i = 0; i < int(points_beg.size()); ++i) 
        chmax(ans, points_end[min(i + k, int(points_end.size()) - 1)] - points_beg[i]);
    cout << ans << '\n';
}
