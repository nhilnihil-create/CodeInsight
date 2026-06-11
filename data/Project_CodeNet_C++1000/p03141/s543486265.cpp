#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define vl vector<ll>


int main() {

    ll N;
    cin >> N;

    ll a, b;
    vl A(N);
    ll ans = 0;
    rep(i, N) {
        cin >> a >> b;
        A[i] = a + b;
        ans -= b;
    }

    sort(A.begin(), A.end(), greater<ll>());

    rep(i, N) if(i%2==0) ans += A[i];

    cout << ans << endl;

    return 0;
}
