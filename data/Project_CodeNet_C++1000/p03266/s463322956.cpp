#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
    int N, K;
    ll ans = 0;
    cin >> N >> K;

    ll cnt = 0;
    if (K % 2 == 0) {
        ll cnt2 = 0;
        for (int i = 1; i <= N; i++) {
            if (i % K == 0) {
                cnt++;
            } else if (i % K == K/2) {
                cnt2++;
            }
        }
        ans += pow(cnt, 3);
        ans += pow(cnt2, 3);
        cout << ans << endl;
    } else {
        for (int i = 1; i <= N; i++) {
            if (i % K == 0) {
                cnt++;
            }
        }
        ans += pow(cnt, 3);
        cout << ans << endl;
    }
}
