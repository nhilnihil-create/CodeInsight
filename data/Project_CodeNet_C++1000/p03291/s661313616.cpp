/*
--------------              |   /
      |                     |  /
      |                     | /
      |             *       |/          |    |         ------            *
      |                     |           |    |        /      \
      |             |       |\          |    |       |       |\          |
   \  |             |       | \         |    |       |       | \         |
    \ |             |       |  \        |    |        \     /   \        |
     V              |       |   \        \__/|         -----     \       |
*/
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(NULL);
#define mem(i,j) memset(i,j,sizeof (i));
#define F first
#define S second
#define lowbit(x) ((x)&(-(x)))
#define siz(v) (long long)(v).size()
typedef int64_t ll;
typedef uint64_t ull;
const double EPS  = 1e-8;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
/*-----------------------------------------------------------------------------------------------------*/
#define int ll

ll mpow(ll a, int b) {
    if(b < 0)
        return 0;
    ll ans = 1;
    for(; b; b>>=1, a = (a*a%MOD))
        if(b&1)
            ans = (ans * a) % MOD;
    return ans;
}

signed main() {
	EmiliaMyWife

    string s;
    cin >> s;

    int n = s.size();
    ll ans = 0;
    map<char,int> cnt, cnt2;
    for(int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }
    for(int i = 0; i < n; i++) {
        cnt[s[i]]--;
        if(s[i]=='B' || s[i]=='?') {
            ll owo = ((cnt2['A']*mpow(3, cnt2['?'])) + cnt2['?']*mpow(3, cnt2['?']-1))%MOD;
            ll ouo = ((cnt['C']*mpow(3, cnt['?'])) + cnt['?']*mpow(3, cnt['?']-1))%MOD;
            ans = (ans + owo*ouo) % MOD;
        }
        //cout << ans << ' ';
        cnt2[s[i]]++;
    }
    cout <<ans;

	return 0;
}
