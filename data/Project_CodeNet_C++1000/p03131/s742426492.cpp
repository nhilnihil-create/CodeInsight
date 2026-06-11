#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll K, A, B;
    cin >> K >> A >> B;

    ll ans = 0;
    if (A+2 < B){
        ll t = A-1;
        ll cnt = (K-t)/2;
        ans += A;
        ans += cnt * (B-A);
        ans += (K-t)%2;
    }else{
        ans = K+1;
    }

    cout << ans << endl;

    return 0;
}
