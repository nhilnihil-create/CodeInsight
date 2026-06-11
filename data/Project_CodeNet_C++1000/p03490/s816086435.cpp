#include <vector>
#include <numeric>
#include <iostream>
using namespace std;
int main() {
    string s; cin >> s;
    int x, y; cin >> x >> y;
    int c = 0;
    while (s[c] == 'F') c++;
    x -= c;
    c++;
    bool h = false;
    vector<int> hor, ver;
    while (c < s.size()) {
        int c0 = c;
        while (c < s.size() && s[c] == 'F') c++;
        if (h) hor.push_back(c-c0);
        else ver.push_back(c-c0);
        h = !h;
        c++;
    }
    x += accumulate(hor.begin(), hor.end(), 0);
    y += accumulate(ver.begin(), ver.end(), 0);
    if (x % 2 != 0 || y % 2 != 0) { cout << "No\n"; return 0; }
    x /= 2; y /= 2;
    bool dp[8000] = {};
    dp[0] = true;
    for (int a : hor) {
        for (int i = x; i >= a; i--) dp[i] = dp[i-a];
    }
    if (!dp[x]) { cout << "No\n"; return 0; }
    fill(dp+1, dp+8000, false);
    for (int a : ver) {
        for (int i = y; i >= a; i--) dp[i] = dp[i-a];
    }
    if (!dp[y]) { cout << "No\n"; return 0; }
    cout << "Yes\n";
}
