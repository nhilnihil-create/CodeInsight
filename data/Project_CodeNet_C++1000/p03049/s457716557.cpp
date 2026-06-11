#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

int calc(int ab, int b, int a) {
    int ret = 0;
    if (ab) {
        ret += ab - 1;
        ab = 1;
    }

    if (ab && b) {
        b--;
        ret++;
    }

    if (ab && a) {
        a--;
        ret++;
    }

    ret += min(b, a);
    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<string> s(N);

    map<int, int> mp;
    int ans = 0;
    rep(i, N) {
        string s;
        cin >> s;
        rep(i, s.size() - 1) {
            if (s[i] == 'A' && s[i + 1] == 'B') ans++;
        }
        bool beginB = s[0] == 'B';
        bool endA = s[s.size() - 1] == 'A';
        if (beginB && endA) {
            mp[0]++;
        } else if (beginB) {
            mp[1]++;
        } else if (endA) {
            mp[2]++;
        }
    }

    ans += calc(mp[0], mp[1], mp[2]);
    cout << ans << endl;
}
