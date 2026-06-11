#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(void)
{
    IOS
    ll k,a,b;
    cin >> k >> a >> b;

    ll ans = 0;
    if (a+1 >= b) ans = k+1;
    else {
        ll k1 = 0;
        ans = 1;
        while(k1 < k) {
            if (ans < a) {
                ll x = min(k-k1,a-ans);
                //cerr << x << endl;
                k1 += x;
                ans += x;
            }
            
            if (k-k1 == 1) {
                ans++;
                k1++;
            } else if (k-k1 >= 2) {
                k1 += 2;
                ans += b-a;
            }
            //cerr << ans << endl;
        }
    }

    cout << ans << '\n';

    return 0;
}