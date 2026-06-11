#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define vec vector<ll>
#define mat vector<vector<ll> >
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=998244353;
const ll mod=998244353;
signed main(){
    ll h,w,n;cin>>h>>w>>n;
    vector<vector<ll> >a(w);
    set<pll>st;
    rep(i,n){
        ll x,y;cin>>x>>y;
        x--;y--;
        st.insert(mp(x,y));
        a[y].pb(x);
    }
    rep(i,w){
        a[i].pb(h);
        st.insert(mp(i,h));
        sort(all(a[i]));
    }
    ll nx=0,ny=0;
    ll ans=h;
    while(nx<h&&ny<w){
        if(st.find(mp(nx+1,ny))!=st.end()){
            ans=min(ans,nx+1);
            break;
        }
        ll p=*upper_bound(all(a[ny]),nx);
        ans=min(ans,p);
        nx++;
        if(st.find(mp(nx,ny+1))==st.end()){
            ny++;
        }
    }
    cout<<ans<<endl;
}