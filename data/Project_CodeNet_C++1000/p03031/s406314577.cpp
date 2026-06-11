#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> light(m,vector<int>(0));
    rep(i, m) {
        int k;
        cin >> k;
        rep(j, k) {
            int s;
            cin >> s;
            light[i].push_back(--s);
        }
    }
    vector<int> p(m);
    rep(i, m) {
        cin >> p[i];
    }
    int c = pow(2,n);
    int ans = c;
    rep(i, c) {
        bitset<10> bit = i;
        rep(j, m) {
            int cnt = 0;
            rep(k, light[j].size()) {
                if (bit.test(light[j][k])) cnt++;
            }
            if (cnt % 2 != p[j]) {
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;
}