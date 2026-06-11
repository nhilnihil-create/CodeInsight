#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[9]={1,0,-1,0,1,1,-1,-1,0};
const ll dx[9]={0,-1,0,1,1,-1,1,-1,0};
template<class T> inline bool chmin(T& a, T b) {
    if (a >= b) {
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
int main(){
    ll n,k,q;cin >> n >> k >>q;
    vl v(n);rep(i,n)cin >> v[i];
    ll ans=INF;
    rep(i,n){
        ll ret=0;
        vl copy=v;
        rep(j,n){
            if(copy[j]<v[i])copy[j]=-1;
        }
        //rep(j,n)cout << copy[j] <<" ";cout << endl;
        vl use;priority_queue<ll,vl,greater<ll>> que,init;
        rep(j,n){
            while(j<n&&copy[j]!=-1){
                que.push(copy[j]);j++;
            }
            while(que.size()>=k){
                use.pb(que.top());que.pop();
            }
            que=init;
        }
        sort(all(use));
        //for(auto p:use)cout << p <<" ";cout << endl;
        if(use.size()>=q)chmin(ans,use[q-1]-use[0]);
        //cout << ans <<endl;
    }
    cout << ans <<endl;
} 