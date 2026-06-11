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
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
signed main(){
    ll n;cin>>n;
    priority_queue<pair<pll,ll>,vector<pair<pll,ll> >,greater<pair<pll,ll> > >miq;
    priority_queue<pair<pll, ll> >maq;
    priority_queue<pair<pll,ll>,vector<pair<pll,ll> >,greater<pair<pll,ll> > >miq2;
    priority_queue<pair<pll, ll> >maq2;
    ll mal=0;
    ll mir=0;
    rep(i,n){
        ll l,r;cin>>l>>r;
        miq.push(mp(mp(r,l),i));
        maq.push(mp(mp(l,r),i));
        mal=max(mal,l);
        mir=min(mir,r);
    }
    maq2=maq;
    miq2=miq;
    ll ans=0,ans1=0;
    set<ll>st;
    ll now=0;
        while(st.size()<n){
            while(st.find(maq.top().se)!=st.end()){
                maq.pop();
            }
            pll k=maq.top().fi;
            ll idx=maq.top().se;
            ll l=k.fi,r=k.se;
            maq.pop();
            if(now<l){
                ans+=l-now;
                now=l;
            }else if(now>r){
                ans+=now-r;
                now=r;
            }
            st.insert(idx);
            if(st.size()==n)break;
            while(st.find(miq.top().se)!=st.end()){
                miq.pop();
            }
            k=miq.top().fi;
            idx=miq.top().se;
            l=k.se,r=k.fi;
            miq.pop();
            if(now<l){
                ans+=l-now;
                now=l;
            }else if(now>r){
                ans+=now-r;
                now=r;
            }
            st.insert(idx);
        }
    maq=maq2,miq=miq2;
    st.clear();
    ans+=abs(now);
    now=0;
        while(st.size()<n){
            while(st.find(miq.top().se)!=st.end()){
                miq.pop();
            }
            pll k=miq.top().fi;
            ll idx=miq.top().se;
            ll l=k.se,r=k.fi;
            miq.pop();
            if(now<l){
                ans1+=l-now;
                now=l;
            }else if(now>r){
                ans1+=now-r;
                now=r;
            }
            st.insert(idx);
            if(st.size()==n)break;
            while(st.find(maq.top().se)!=st.end()){
                maq.pop();
            }
            k=maq.top().fi;
            idx=maq.top().se;
            l=k.fi,r=k.se;
            maq.pop();
            if(now<l){
                ans1+=l-now;
                now=l;
            }else if(now>r){
                ans1+=now-r;
                now=r;
            }
            st.insert(idx);
        }
    ans1+=abs(now);
    cout<<max(ans,ans1)<<endl;
}