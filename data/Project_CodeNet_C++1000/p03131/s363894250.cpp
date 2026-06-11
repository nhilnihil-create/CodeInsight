#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for(int i=(start); i<(int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

typedef long long ll;
typedef unsigned long long ull;

ll K, A, B;

int main(void) {
    cin >> K >> A >> B;

    if (A > B) {
        cout << 1 + K << endl;
        return 0;
    }

    ll ans = 0;
    ll r = A - 1; // 叩く回数

    ll k = (K - r) / 2; // 増殖できる回数
    ans = B + (k - 1) * (B - A);
    ans += ((K - r) % 2); // 余った回数

    ans = max(1 + K, ans);

    cout << ans << endl;



    return 0;
}