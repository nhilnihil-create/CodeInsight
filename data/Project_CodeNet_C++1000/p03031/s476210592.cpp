#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n , m;
    cin >> n >> m;

    vector<int> adj[n];
    for (int i = 0 ;i < m ;i++) {
        int k;
        cin >> k;
        while (k--) {
            int s;
            cin >> s;
            adj[s - 1].push_back(i);
        }
    }

    vector<int> p(m);
    for (int i = 0 ;i < m ;i++)
        cin >> p[i];

    int ans = 0;
    for (int i = 0 ;i < (1 << n) ;i++) {
        vector<int> cnt(m , 0);
        for (int j = 0 ;j < n ;j++) {
            if (i & (1 << j)) {
                for (int b : adj[j])
                    cnt[b]++;
            }
        }

        bool good = 1;
        for (int j = 0 ;j < m ;j++)
            good &= p[j] == cnt[j] % 2;

        ans += good;
    }

    cout << ans;
}