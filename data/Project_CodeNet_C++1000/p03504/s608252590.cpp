#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using tvinfo = tuple<int, int, int>;

int main() {
    int N, C; cin >> N >> C;
    vector<vector<int>> d(C+1, vector<int>(100005, 0));

    for (int i = 0; i < N; i++)
    {
        int s, t, c; cin >> s >> t >> c;
        c--;
        d[c][s-1]++;
        d[c][t]--;
    }
    for (int j = 0; j < C; j++)
    {
        for (int i = 0; i < 100005; i++)
        {
            if(i>0) d[j][i] += d[j][i-1];
            if(d[j][i]>0) d[C][i]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < 100005; i++) ans = max(ans, d[C][i]);
    cout << ans << endl;
}