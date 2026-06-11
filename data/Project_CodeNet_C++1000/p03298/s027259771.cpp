#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<map<string, int>> cnt(n + 1);
    for (int mask = 0; mask < 1 << n; mask++) {
        string t1, t2;
        for (int i = 0; i < n; i++) {
            (mask >> i & 1 ? t1 : t2) += s[i];
        }
        reverse(begin(t2), end(t2));
        cnt[t1.size()][t1 + t2]++;
    }
    long long ans = 0;
    for (int mask = 0; mask < 1 << n; mask++) {
        string t1, t2;
        for (int i = 0; i < n; i++) {
            (mask >> i & 1 ? t1 : t2) += s[n + i];
        }
        reverse(begin(t2), end(t2));
        ans += cnt[t2.size()][t2 + t1];
    }
    cout << ans << endl;
    return 0;
}
