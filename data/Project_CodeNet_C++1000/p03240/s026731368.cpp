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
            if (H == 0) continue;
            bool flag = true;
            for (int i = 0; i < N; i++) {
                if (h[i] != max(H - abs(x[i] - cx) - abs(y[i] - cy), 0)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << cx << " " << cy << " " << H << "\n";
                return 0;
            }
            
        }
    }

    return 0;
}