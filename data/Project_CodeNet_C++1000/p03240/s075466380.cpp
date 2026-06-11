#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int N;
    cin >> N;
    int x[N], y[N], h[N];
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> h[i];
    }
    vector<vector<int>> d;
    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            int H = 0;
            for (int i = 0; i < N; i++) {
                if (h[i] == 0) continue;
                ll t = abs(x[i] - cx) + abs(y[i] - cy);
                if (H == 0) {
                    H = t + h[i];
                } else if(H != t + h[i]){
                    H = 0;
                    break;
                }
            }
            if (H != 0) {
                d.push_back(vector<int>({cx, cy, H}));
            }
            
        }
    }
    for (vector<int> v : d) {
        bool flag = true;
        for (int i = 0; i < N; i++) {
            if (h[i] != max(v[2] - abs(x[i] - v[0]) - abs(y[i] - v[1]), 0)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << v[0] << " " << v[1] << " " << v[2] << "\n";
            return 0;
        }
    }
    return 0;
}