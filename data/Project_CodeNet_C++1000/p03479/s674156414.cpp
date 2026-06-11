#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, N) for (ll i = 0; i < (N); i++)
#define For(i, a, b) for (ll i = (a); i < (b); i++)
#define all(A) (A).begin(), (A).end()

int main(){
    ll X, Y;
    cin >> X >> Y;
    ll ans = 1;
    ll tmp = X;
    while (tmp * 2 <= Y) {
        ans++;
        tmp *= 2;
    }

    cout << ans << endl;

    return 0;
}
