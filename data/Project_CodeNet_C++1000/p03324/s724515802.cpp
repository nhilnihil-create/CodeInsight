#include<iostream>
using namespace std;

int main() {
    int D, N; cin >> D >> N;
    long int ans;
    if (N == 100) {
        N = 101;
    }
    if (D == 0) {
        ans = N;
    } else if (D == 1) {
        ans = 100 * N;
    } else if (D == 2) {
        ans = 10000 * N;
    }
    cout << ans << endl;
}
