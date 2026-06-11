#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N), h(N);
    rep(i, N) cin >> x[i] >> y[i] >> h[i];
    
    for (int Cx = 0; Cx <= 100; ++Cx) {
        for (int Cy = 0; Cy <= 100; ++Cy) {
            int H = -1;
            rep(i, N) {
                if (Cx == x[i] && Cy == y[i]) H = h[i];
            }
            if (H == -1) {
                rep(i, N) {
                    if (h[i] != 0) {
                        H = h[i] + abs(Cx - x[i]) + abs(Cy - y[i]);
                        break;
                    }
                }
            }
            if (H == -1) H = 1;
            
            bool judge = true;
            rep(i, N) {
                if (max(H - abs(Cx - x[i]) - abs(Cy - y[i]), 0) != h[i]) judge = false;
            }
            if (judge) {
                cout << Cx << " " << Cy << " " << H << endl;
                return 0;
            }
        }
    }
}
