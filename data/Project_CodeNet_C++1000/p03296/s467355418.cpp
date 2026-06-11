#include <iostream>
using namespace std;
int main() {
    int N, ans = 0;
    cin >> N;
    for (int i = 0, a, prev = 0, cnt = 1; i < N; i++) {
        cin >> a;
        if (a == prev) cnt++;
        if (a != prev || i == N - 1) {
            ans += cnt / 2;
            cnt = 1;
        }
        prev = a;
    }
    cout << ans << endl;
}
