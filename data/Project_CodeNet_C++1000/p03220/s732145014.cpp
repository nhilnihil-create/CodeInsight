#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int T, A; cin >> T >> A;
    int min_diff = 10000000;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int H; cin >> H;
        int diff = 1000 * abs(A - T + H * 0.006);
        if (min(min_diff, diff) == diff) {
            min_diff = diff;
            ans = i + 1;
        }
    }
    cout << ans << endl;
}
