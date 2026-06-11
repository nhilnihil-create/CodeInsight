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
    int n; cin>>n;
    vll a(n);
    rep(i,n) cin>>a[i];
    ll l=-1e10,r=1e10;
    while(r-l>2){
        ll c1 = (l*2+r)/3;
        ll c2 = (l+r*2)/3;
        ll s1=0, s2=0;
        rep(i,n) s1+=abs(a[i]-(c1+i+1));
        rep(i,n) s2+=abs(a[i]-(c2+i+1));
        if (s1<s2){
            r = c2;
        }else{
            l = c1;
        }
    }
    ll b = (l+r)/2;
    ll ans=0;
    rep(i,n) ans+=abs(a[i]-(b+i+1));
    cout<<ans<<endl;
    return 0;
}
