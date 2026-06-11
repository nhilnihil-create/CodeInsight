#include "bits/stdc++.h"

using namespace std;
using pii = pair <int, int>;
using ppi = pair <pii, pii>;

#define f first
#define s second

int main() {
    int h, w; cin >> h >> w;
    int a[h][w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    vector <ppi> ans;
    for (int i = 0; i < h; i++) {
        vector <int> odd;
        for (int j = 0; j < w; j++) {
            if (a[i][j] & 1) odd.push_back(j);
        }

        int sz = odd.size();
        for (int j = 0; j + 1 < sz; j += 2) {
            int c1 = odd[j], c2 = odd[j + 1];
            while (c1 != c2) {
                ans.push_back({pii(i, c1), pii(i, c1 + 1)});
                c1++;
            }
        }

        if (sz & 1) {
            int c1 = odd[sz - 1], c2 = w - 1;
            while (c1 != c2) {
                ans.push_back({pii(i, c1), pii(i, c1 + 1)});
                c1++;
            }

            if (i < h - 1) {
                ans.push_back({pii(i, w - 1), pii(i + 1, w - 1)});
                a[i + 1][w - 1]++;
            }
        }
    }

    cout << ans.size() << endl;
    for (auto step : ans) {
        cout << step.f.f + 1 << " " << step.f.s + 1 << " " << step.s.f + 1 << " " << 
        step.s.s + 1 << endl;
    }
}