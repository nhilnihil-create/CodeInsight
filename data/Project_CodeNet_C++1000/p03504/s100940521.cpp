#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int inf = 1e9;
constexpr ll linf = 1e18;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, C; cin >> n >> C;
    vector<int> s(n), t(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i] >> c[i];
        c[i]--;
    }

    int last = *max_element(t.begin(), t.end());
    
    vector<vector<int>> imos(last + 1, vector<int>(C, 0));

    for (int i = 0; i < n; i++) {
        imos[s[i] - 1][c[i]]++;
        imos[t[i]][c[i]]--;
    }

    vector<int> record(last + 1, 0);
    for (int i = 0; i <= last; i++) {
        for (int j = 0; j < C; j++) {
            if (i < last) imos[i + 1][j] += imos[i][j];
            if (imos[i][j]) record[i]++;
        }
    }

    int ans = *max_element(record.begin(), record.end());
    cout << ans << endl;
    return 0;
}