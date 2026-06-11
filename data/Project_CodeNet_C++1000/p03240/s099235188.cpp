#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void){
    int N; cin >> N;
    vector<int> x(N), y(N), h(N);
    for (int i = 0; i < N; ++i)
        cin >> x[i] >> y[i] >> h[i];
    // 中心座標について全探索
    for (int cx = 0; cx <= 100; ++cx){
        for (int cy = 0; cy <= 100; ++cy){
            int H = -1;
            for (int i = 0; i < N; ++i){
                if (h[i] == 0) continue;
                int tmp = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
                if (H == -1) H = tmp;
            }
            bool ok = true;
            for (int i = 0; i < N; ++i){
                int hi = max(0, H - abs(x[i] - cx) - abs(y[i] - cy));
                ok &= h[i] == hi;
            }
            if (ok){
                cout << cx << " " << cy << " " << H << endl;
                return 0;
            }
        }
    }
    return 0;
}