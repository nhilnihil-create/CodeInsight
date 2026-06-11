#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

int main(void)
{
    ll n, m;
    cin >> n >> m;
    ll a, b, ans;
    a = min(n, m);
    b = max(n, m);
    if(a == 1) {
        if(b == 1) ans = 1;
        else ans = b - 2;
    } 
    else if(a == 2) {
        ans = 0;
    } else { // a > 2
        ans = (a - 2) * (b - 2);
    }
    cout << ans << endl;
}
