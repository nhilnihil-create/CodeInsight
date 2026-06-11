#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

const ll mod = 1000000007;

int main() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;

    // 圧縮
    vector<int> cnt(n,0);
    int idx = 0;
    int c = 1;
    if (s[0] == '0') {
        cnt[0] = 0;
        idx++;
    }
    rep(i,n-1) {
        if (s[i] != s[i+1]) {
            cnt[idx] = c;
            c = 1;
            idx++;
        } else {
            c++;
        }
    }
    cnt[idx] = c;
    idx++;
    if (s[n-1] == '0') {
        cnt[idx] = 0;
        idx++;
    }

    // 尺取り
    int ans = 0;
    int nsum = 0;
    if (2*k+1 >= idx) {
        for (int c:cnt) nsum += c;
        cout << nsum << endl;
        return 0;
    }
    rep(i,2*k+1) nsum += cnt[i];
    ans = nsum;
    for (int i = 2*k+1; i < idx; i += 2) {
        nsum = nsum - cnt[i-2*k-1] - cnt[i-2*k] + cnt[i] + cnt[i+1];
        ans = max(ans, nsum);
    }
    cout << ans << endl;
    return 0;
}