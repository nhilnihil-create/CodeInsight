#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int A,B,C;
    ll X,Y;
    ll ans = 1000000000;
    cin >> A >> B >> C >> X >> Y;

    rep(i, 1000001){
        ll total = max((ll)0,X-i)*A+max((ll)0,Y-i)*B+2*i*C;
        ans = min(total,ans);
    }

    cout << ans << endl;

    return 0;
}