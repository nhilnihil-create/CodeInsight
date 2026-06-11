#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    string s;
    cin >> s;
    int cnt = 0, cnt1 = 0;
    rep(i, s.size()) {
        if (i % 2 == 0) {
            if (s[i] != '0')
                cnt++;
        } else {
            if (s[i] != '1')
                cnt++;
        }
    }

    rep(i, s.size()) {
        if (i % 2 == 0) {
            if (s[i] != '1')
                cnt1++;
        } else {
            if (s[i] != '0')
                cnt1++;
        }
    }

    cout << min(cnt, cnt1) << endl;
}