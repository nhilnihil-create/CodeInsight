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
typedef pair<l_l,ll> lll;
typedef vector<string> vs;
const ll dx[4]={1,-1,0,0};
const ll dy[4]={0,0,1,-1};
#define pb push_back
#define sz(x) (int)(x).size()
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
ll n,k,q;
bool p[2020];
ll a[2020];
ll f(ll val){
    rep(i,n){
        if(a[i]<val)p[i]=true;
        else p[i]=false;
    }
    vl s,t;
    rep(i,n+1){
        if(p[i]||i==n){
            sort(t.begin(),t.end());
            if(sz(t)>=k){
                for(int j=0;j<sz(t)-k+1;j++){
                    s.pb(t[j]);
                }
            }
            t.clear();
        }else t.pb(a[i]);
    }
    sort(s.begin(),s.end());
    if(sz(s)<q)return LINF;
    else return s[q-1]-s[0];
}
int main(){
    cin>>n>>k>>q;
    rep(i,n)cin>>a[i];
    ll ans=LINF;
    rep(i,n){
        chmin(ans,f(a[i]));
    }
    cout<<ans<<endl;
    return 0;
}