#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)a; i <= (int)b; ++i)
#define sz(s) (int)s.size()
#define all(v) v.begin(),v.end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf = (ll)1e14;
const ll N = (ll)2e5+77;
const ll mod = (ll)1e9+7;

int n,m,k,x,y,ans;
int pre[N],bit[1<<26];
string s;

int main() {
    fast;
    cin >> s;
    n = sz(s);

    forn(i, n) {
        pre[i + 1] = pre[i] ^ (1 << (s[i] - 'a'));
    }

    forn(i, 1 << 26) bit[i] = 1e9;

    bit[0] = 0;
    for1(i, n) {
        int group = bit[pre[i]];

        forn(j, 26) group = min(group, bit[pre[i] ^ (1 << j)]);
        group++;

        bit[pre[i]] = min(bit[pre[i]], group);
        ans = group;
    }
    cout << ans << endl;
    return 0;
}