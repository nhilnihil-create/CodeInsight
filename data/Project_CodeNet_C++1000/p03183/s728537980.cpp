#include <bits/stdc++.h>

#define null               ""
#define all(dat)           dat.begin(), dat.end()
#define over(msg)          cout << msg << endl, exit(0);
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

int n, mw, ms, to, w[1005], s[1005], v[1005], id[1005];
num pre[20005], dp[20005], ans;

bool cmp(int i, int j) {
    return w[i] + s[i] < w[j] + s[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    cont (i, n) {
        cin >> w[i] >> s[i] >> v[i];
        to = max(to, w[i] + s[i] + 1);
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    cont (pi, n) {
        int i = id[pi];
        memset(dp, 0, sizeof(dp));
        loop (j, s[i] + 1) {
            dp[j + w[i]] = pre[j] + v[i];
        }
        loop (j, to) {
            pre[j] = max(pre[j], dp[j]);
        }
    }
    loop (i, to) {
        ans = max(ans, pre[i]);
    }
    cout << ans << endl;
}
