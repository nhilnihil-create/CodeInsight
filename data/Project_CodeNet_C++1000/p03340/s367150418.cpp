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
    int n; cin >> n;
    vector<int> v(n);
    REP(i,n) cin >> v[i];

    ll ans = 0;
    int cnt = 0;
    int l = 0,r = 0;
    REP(i,n) {
        while(cnt+v[i] != (cnt ^ v[i])) {
            cnt -= v[l];
            ans += r-l;
            l++;
        }
        cnt += v[i];
        r++;
        // cerr << ans << endl;
    }
    // cerr << l << " " << r << endl;
    FOR(i,l,r) {
        ans += r-i;
    }

    cout << ans << '\n';

    return 0;
}