#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
void dfs(int x, int depth) {
    if(depth == 0) {
        if(x <= n) {
            map<int, bool> mp;
            while (x) {
                for (int i = 3; i < 8; i+=2) {
                    if(x%10 == i) {
                        mp[i] = 1;
                        break;
                    }
                }
                x /= 10;
            }
            int cnt = 0;
            for (auto p : mp) {
                cnt += p.second;
            }
            if(cnt == 3) {
                ans++;
            }
        }
        return;
    }

    x *= 10;
    for (int i = 3; i < 8; i += 2) {
        dfs(x + i, depth - 1);
    }
}
void solve () {
    cin >> n;
    string s = to_string(n);
    int sz = (int) s.size();
    for (int j = 2; j < sz; j++) {
        for (int i = 3; i < 8; i+= 2) {
           dfs(i, j);
        }
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
