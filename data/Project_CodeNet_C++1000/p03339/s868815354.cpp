#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    vector<int> lw(N, 0), re(N, 0);
    rep(i, N) {
        if (s[i] == 'W')
            lw[i] = 1;
        if (s[i] == 'E')
            re[i] = 1;
    }

    rep(i, N - 1) { lw[i + 1] += lw[i]; }

    for (int i = N - 1; i > 0; i--) {
        re[i - 1] += re[i];
    }

    rep(i, N) {
        if (s[i] == 'W')
            lw[i]--;
        if (s[i] == 'E')
            re[i]--;
    }

    int res = 1e8;
    rep(i, N) { res = min(res, re[i] + lw[i]); }
    cout << res << endl;
}