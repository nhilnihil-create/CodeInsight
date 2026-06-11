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

#define INF 1e12

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b,q; cin>>a>>b>>q;
    vll s(a+2),t(b+2);
    s[0]=t[0]=-INF;
    s[a+1]=t[b+1]=INF;
    rep(i,a) cin>>s[i+1];
    rep(i,b) cin>>t[i+1];
    while(q--){
        ll x; cin>>x;
        auto itr = upper_bound(all(s),x); itr--;
        ll sl = *itr;
        ll sr = *lower_bound(all(s),x);
        itr = upper_bound(all(t),x); itr--;
        ll tl = *itr;
        ll tr = *lower_bound(all(t),x);
        ll ans=max(x-sl,x-tl);
        chmin(ans,max(sr-x,tr-x));
        chmin(ans,tr-sl+min(x-sl,tr-x));
        chmin(ans,sr-tl+min(x-tl,sr-x));
        cout<<ans<<"\n";
    }
    return 0;
}
