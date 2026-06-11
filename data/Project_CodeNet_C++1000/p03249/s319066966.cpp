#include<bits/stdc++.h>
//300iq
#define ll long long
#define pii pair<int,int> 
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
vector<pair<ll,int> > e;
map<ll,int> ret;
int n;
inline void die(){
    puts("-1");
    exit(0);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        ret[x]=i;
        e.pb(mp(x,i));
    }
    sort(e.begin(),e.end());
    reverse(e.begin(),e.end());
    ll x=e.back().first;
    vector<int> siz(n,1);
    vector<ll> dp(n,0);
    vector<pii> ans;
    for(int i=0;i<e.size();i++){
        pair<ll,ll> c=e[i];
        if(c.first==x) continue;
        if(siz[c.se]*2>=n)
            die();
        ll need=c.first+2*siz[c.se]-n;
        if(!ret.count(need))
            die();
        int par=ret[need];
        dp[par]+=dp[c.se]+siz[c.se];
        siz[par]+=siz[c.se];
        ans.pb(mp(c.se+1,par+1));
    }
    if(dp[e.back().se]!=x)
        die();
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].fi<<" "<<ans[i].se<<endl;
    return 0;
}