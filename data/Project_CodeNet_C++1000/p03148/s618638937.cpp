#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
ll n,k;
int main(){
    cin>>n>>k;
    vl t(n),d(n);
    vector<l_l> p(n);
    rep(i,n){
        cin>>t[i]>>d[i];
        p[i]={d[i],t[i]};
    }
    sort(p.rbegin(),p.rend());
    set<ll> s;
    stack<ll> st;
    ll ans=0;
    rep(i,k){
        if(s.count(p[i].se)){
            st.push(p[i].fi);
        }
        s.insert(p[i].se);
        ans+=p[i].fi;
    }
    ll sum=ans;
    ans+=(ll)s.size()*(ll)s.size();
    for(int i=k;i<n;i++){
        if(st.empty()) break;
        if(s.count(p[i].se))continue;
        s.insert(p[i].se);
        sum-=st.top();
        st.pop();
        sum+=p[i].fi;
        chmax(ans,sum+(ll)s.size()*(ll)s.size());
    }
    cout<<ans<<endl;
    return 0;
}