#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = 100;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        int cnt = 0;
        while (A % 2 == 0) {
            A = A / 2;
            cnt += 1;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}