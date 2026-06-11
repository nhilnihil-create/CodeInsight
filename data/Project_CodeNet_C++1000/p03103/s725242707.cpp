#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    long n, m;
    cin >> n >> m;
    vector<pair<long,long>> s(n);
    rep(i, n) {
        cin >> s[i].first >> s[i].second; // 値段→本数
    }
    sort(s.begin(), s.end()); // 値段の安い順にソート
    // rep(i, n) {
    //     cout << s[i].first << " " << s[i].second << endl;
    // }
    long k = 0, sum = 0, i = 0;
    while (k < m) {
        long yen = s[i].first, hon = s[i].second;
        if (k + hon < m) {
            k += hon;
            sum += yen * hon;
        } else {
            sum += yen * (m - k);
            k = m;
        }
        i++;
    }
    cout << sum << endl;
}