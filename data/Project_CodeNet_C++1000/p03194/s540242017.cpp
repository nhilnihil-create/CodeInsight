#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << endl;
#define CFYN(n) cout << ( (n) ? "YES":"NO") << endl;
using ll = long long;
using ull = unsigned long long;

int main(void)
{
    IOS
    ll n,p;
    cin >> n >> p;

    ll ans = 1;
    if (n == 1) {
        ans = p;
    } else {
        ll x = pow(p,1.0/n);
        while(x > 1) {
            ll y = pow(x,n);
            if (p % y == 0) {
                p /= y;
                ans *= x;
            } else {
                x--;
            }
        }
    }

    cout << ans << endl;

    return 0;
}