// 解説見た
#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
// 4/2 = 
// 4/4 = 1/2 + 1/4 + 1/4
// 4/6 = 
void solve() {
    lint N; cin >> N;
    for (int h=1; h<=3500; h++) {
        for (int n=h; n<=3500; n++) {
            double w = double(N*h*n) / double(4*h*n-N*n-N*h);
            if (w != INFINITY && floor(w) == w && w > 0) {
                cout << h << ' ' << n << ' ' << lint(w) << endl;
                return;
            }
        }
    }
}
int main() {
    // 12/3N = 
    solve();
}