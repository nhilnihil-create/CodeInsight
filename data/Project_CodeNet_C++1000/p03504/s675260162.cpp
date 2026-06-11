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
    
    auto f = [&](int K) {
        vector<int> T(K, -1);
        for (auto tmp : tv) {
            int s, t; tie(s, t) = tmp;
            bool ok = true;
            for (int i = 0; i < K; i++) {
                if (T[i] < s) { T[i] = t; break; }
                if (i + 1 == K) ok = false;
            }
            if (!ok) return false;
        }
        return true;
    };
    
    int ok = C, ng = 0;
    while (abs(ok-ng) > 1) {
        int mid = (ok+ng)/2;
        if (f(mid)) ok = mid;
        else ng = mid;
    }
    
    cout << ok << endl;
    return 0;
}