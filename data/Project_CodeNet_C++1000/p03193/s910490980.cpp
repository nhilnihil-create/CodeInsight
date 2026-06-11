#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, H, W;
    cin >> N >> H >> W;
    int64_t ans = 0;
    for (int64_t i = 0; i < N; i++) {
        int64_t A, B;
        cin >> A >> B;
        ans += (A >= H && B >= W);
    }
    cout << ans << endl;
}