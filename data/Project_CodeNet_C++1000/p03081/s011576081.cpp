#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF=1001001001;
const ll LINF=1001001001001001001;
#define overload4(_1,_2,_3,_4,name,...) name
#define rep1(n) for(ll i=0;i<(n);++i)
#define rep2(i,n) for(ll i=0;i<(n);++i)
#define rep3(i,a,b) for(ll i=(a);i<(b);++i)
#define rep4(i,a,b,c) for(ll i=(a);i<(b);i+=(c))
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define vec vector<ll>
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}

void solve(){
    ll n,q;cin>>n>>q;
    string s;cin>>s;
    vector<char> t(q);
    vector<char> d(q);
    rep(i,q)cin>>t[i]>>d[i];
    ll lok=n;
    ll lng=-1;
    while(lok-lng>1){
        ll mid=(lok+lng)/2;
        ll tmp=mid;
        rep(i,q){
            if(s[tmp]==t[i]){
                tmp+=d[i]=='L'?-1:1;
            }
            if(tmp<0)break;
        }
        if(tmp<0)lng=mid;
        else lok=mid;
    }
    ll rng=n;
    ll rok=-1;
    while(rng-rok>1){
        ll mid=(rok+rng)/2;
        ll tmp=mid;
        rep(i,q){
            if(s[tmp]==t[i]){
                tmp+=d[i]=='L'?-1:1;
            }
            if(tmp>=n)break;
        }
        if(tmp>=n)rng=mid;
        else rok=mid;
    }
    cerr<<lok<<' '<<rok<<'\n';
    cout<<max(0ll,rok-lok+1)<<'\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
