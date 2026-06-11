#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ld long double
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

/* Some Libraries */

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vector<vll> v(3, vll(n));
    rep(i,n)rep(j,3) cin>>v[j][i];
    ll ans=0;
    rep(c,8){
        vll t;
        rep(i,n){
            ll sum=0;
            rep(j,3){
                int sgn = (c>>j&1)?1:-1;
                sum+=sgn*v[j][i];
            }
            t.pb(sum);
        }
        sort(rall(t));
        ll cand=0;
        rep(i,m) cand+=t[i];
        chmax(ans,cand);
    }
    cout<<ans<<endl;
    return 0;
}
