#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int N; cin >> N;
    int T, A; cin >> T >> A; T *= 1000; A *= 1000;
    int ans = -1, x = 100000000;
    rep(i, N) {
        int h; cin >> h;
        int t = T - h * 6;
        if (abs(t - A) < x) { x = abs(t - A); ans = i + 1; }
    }
    cout << ans << endl;
    return 0;
}