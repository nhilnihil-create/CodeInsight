#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = sz(s);
    const int INF = INT_MAX / 10;
    vi dp(1 << 26, INF), a(n + 1);
    dp[0] = 0;
    rep(i, n)a[i + 1] = a[i] ^ (1<<(s[i] - 'a'));

    vi pal(26 + 1);
    rep(i, 26)pal[i] = 1 << i;
    int ans = 0;
    rep(i, n) {
        int mi = INF;
        each(p, pal) {
            smin(mi, dp[a[i+1]^p] + 1);
        }
        smin(dp[a[i + 1]], mi);
        ans = mi;
    }
    cout << ans << endl;
}
