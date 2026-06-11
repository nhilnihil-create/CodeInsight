#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    string S;
    cin >> S;

    vector<int> cnt(3);
    for (char c : S) cnt[c - 'a']++;
    sort(cnt.begin(), cnt.end());

    int ma = 0;
    for (int x : cnt) ma = max(ma, x - cnt[0]);
    cout << (ma > 1 ? "NO" : "YES") << endl;
}
