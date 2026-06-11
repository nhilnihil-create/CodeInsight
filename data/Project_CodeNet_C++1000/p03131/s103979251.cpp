#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    ll K, A, B;
    cin >> K >> A >> B;
    if (B - A <= 1 || A >= K) {
        cout << K + 1 << endl;
        return 0;
    }

    ll ans = 0;
    ans = A + (B - A) * ((K - A + 1) / 2);
    if ((K - A + 1) % 2 != 0)
        ans++;

    cout << ans << endl;
}