#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(j, m) for (int j = 0; j < (int)(m); j++)
#define rep2(i, l, n) for (int i = l; i < (int)(n); i++)


int main() {
    ll N,A,B;
    cin >> N >> A >> B;
    ll ans = 0;
    rep2(i, 1, N + 1) {
        ll j = i%10 + (i/10)%10 + (i/100)%10 + (i/1000)%10 + (i/10000)%10;
        if (A <= j && j <= B) {
            ans += i;
        }
    }
    cout << ans << endl;
}

