#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    vector<char> A;
    char prev = '?';
    rep(i, s.size()) {
        if (prev == 'B' && s[i] == 'C')
            A.back() = 'D';
        else
            A.push_back(s[i]);
        prev = s[i];
    }

    ll ans = 0, cnt = 0;
    bool judge = 0;
    for (int i = 0; i < A.size(); i++) {
        if (!judge && A[i] == 'A') {
            judge = 1, cnt++;
        } else if (judge && A[i] == 'A') {
            cnt++;
        } else if (A[i] == 'D') {
            ans += cnt;
        } else
            cnt = 0, judge = 0;
    }

    cout << ans << endl;
}