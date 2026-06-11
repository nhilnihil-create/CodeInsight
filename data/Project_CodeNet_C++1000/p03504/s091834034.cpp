#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
const int TIME_MAX = 100100;

int main() {
    int N, C;
    scanf("%d%d", &N, &C);
    vector<vector<int>> time(TIME_MAX, vector<int> (C, 0));
    for (int i = 0; i < N; i++) {
        int s, t, c;
        scanf("%d%d%d", &s, &t, &c);
        time[s][c-1]++; time[t][c-1]--;
    }
    
    vector<pair<int, int>> tv;
    for (int c = 0; c < C; c++) {
        int s;
        for (int i = 0; i < TIME_MAX; i++) if (time[i][c] != 0) {
            if (time[i][c] == 1) s = i;
            if (time[i][c] == -1) { tv.emplace_back(s, i); }
        }
    }
    
    sort(tv.begin(), tv.end());
    
    int ans = 0, M = tv.size();
    vector<bool> use(M, false);
    for (int tmp = 0; tmp < C; tmp++) {
        int now = 0;
        bool fin = true;
        for (int i = 0; i < M; i++) if (!use[i]) {
            if (fin) fin = false;
            int s, t; tie(s, t) = tv[i];
            if (s <= now) continue;
            use[i] = true;
            now = t;
        }
        if (fin) break;
        ans++;
    }
    
    cout << ans << endl;
    return 0;
}
