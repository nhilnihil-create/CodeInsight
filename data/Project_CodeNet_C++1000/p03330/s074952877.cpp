#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

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
    int n; cin>>n;
    int c; cin>>c;
    vector<vi> D(c, vi(c));
    rep(i,c)rep(j,c) cin>>D[i][j];
    vector<vi> E(3, vi(c));
    rep(i,n)rep(j,n){
        int x; cin>>x; x--;
        E[(i+j)%3][x]++;
    }
    ll ans=LONG_LONG_MAX;
    rep(i,c)rep(j,c)rep(k,c){
        if (i==j || j==k || k==i) continue;
        ll sum=0;
        rep(l,c){
            sum += (ll)E[0][l]*D[l][i];
            sum += (ll)E[1][l]*D[l][j];
            sum += (ll)E[2][l]*D[l][k];
        }
        chmin(ans,sum);
    }
    cout<<ans<<"\n";
    return 0;
}
