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
    
    rep(Cx, 101) rep(Cy, 101) {
        int H = -1;
        rep(i, N) {
            if (h[i] != 0) {
                H = h[i] + abs(Cx - x[i]) + abs(Cy - y[i]);
                break;
            }
        }
        bool judge = true;
        rep(i, N) {
            if (h[i] != max(0, H - abs(Cx - x[i]) - abs(Cy - y[i]))) {
                judge = false;
            }
        }
        if (judge) {
            printf("%d %d %d\n", Cx, Cy, H);
            break;
        }
    }
}