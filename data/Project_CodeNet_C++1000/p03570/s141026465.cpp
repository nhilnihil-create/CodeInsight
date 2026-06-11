#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define eb emplace_back
#define mp make_pair

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;


int dp[1<<26], INF;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(dp, 0x7f, sizeof dp);
    INF = dp[0];

    int mask = 0;
    dp[0] = 0;
    string s; cin >> s;

    int ans;
    for (char c : s) {
        int d = c-'a';
        mask ^= 1<<d;

        ans = INF;
        ans = min(ans, 1 + dp[mask]);
        forn(e,26) ans = min(ans, 1 + dp[mask ^ (1<<e)]);
        dp[mask] = min(dp[mask], ans);
    }
    cout << ans << endl;

    return 0;
}
