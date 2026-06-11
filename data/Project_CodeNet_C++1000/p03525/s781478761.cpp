#include <bits/stdc++.h>
using namespace std;
int main () {
    int N;
    cin >> N;
    vector<int> D[25];
    D[0].push_back(0);
    D[24].push_back(0);
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        if (x == 12) {
            D[x].push_back(i);
        }
        else {
            D[x].push_back(i);
            D[24-x].push_back(i);
        }
    }
    for (int k = 12; k >= 0; k--) {
        if (k == 0) {
            puts("0");
            break;
        }
        set<int> used;
        int x = 0;
        while (1) {
            bool f = 0;
            for (int i = x; i <= 24; i++) {
                for (auto e: D[i]) {
                    if (used.find(e) == used.end()) {
                        used.insert(e);
                        f = 1;
                        x = i+k;
                        break;
                    }
                }
                if (f) break;
            }
            if (!f) break;
        }
        if (x > 24) continue;
        if (used.size() == N+1) {
            cout << k << endl;
            return 0;
        }
    }
}