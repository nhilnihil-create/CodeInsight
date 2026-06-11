#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = n - 1; i >= 0; i--)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define debug(x) cout<<#x<<": "<<x<<endl
 
#define ld double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
 
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define INF 1000000000000000000

ll n;
pair<pair<ll, ll>, pair<ll, ll> > p[1001];
ll dp[1001][10002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    fr(i,1,n)   
    {
        ll w,s,v;
        cin >> w >> s >> v;

        p[i] = mp(mp(s+w,s),mp(w,v));
    }

    sort(p, p+n+1);

    fr(i,1,n)
    {
        fr(j,0,10001)
        {
            dp[i][j] = dp[i-1][j];
        }

        ll s = p[i].ff.ss;
        ll w = p[i].ss.ff;
        ll v = p[i].ss.ss;

        fr(j,0,s)
        {
            if(j+w>10000)
                dp[i][10001] = max(dp[i][10001], dp[i-1][j]+v);
            else
                dp[i][j+w] = max(dp[i][j+w], dp[i-1][j]+v);
        }
    }

    ll ans = 0;

    fr(i,0,10001)
    {
        ans = max(ans, dp[n][i]);
    }

    cout << ans << endl;
}