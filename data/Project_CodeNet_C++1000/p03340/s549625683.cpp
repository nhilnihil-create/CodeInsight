#pragma GCC optimize("O3")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define int long long

string per(int n) {
    string s;
    if (n == 0) {
        s += '0';
        return s;
    }
    while (n > 0) {
        if (n % 2) s += '1';
        else s += '0';
        n /= 2;
    }
    return s;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int> vec(n), f(23, 0);
    for (int i = 0; i < n; ++i) cin >> vec[i];
    int l = 0, r = 0, ans = 0;
    while (l < n) {
        if (r == n) {
            ans += r - l;
            l++;
            continue;
        }
        while (true) {
            if (r == n) break;
            string s = per(vec[r]);
            bool flag = true;
            //cout << s << endl;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == '1' && f[i] == 1) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == '1') f[i] += 1;
            }
            r++;
        }
        //cout << l << " " << r << endl;
        ans += r - l;
        string s = per(vec[l]);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') f[i]--;
        }
        l++;
    }
    cout << ans;
}
