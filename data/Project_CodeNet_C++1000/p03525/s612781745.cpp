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

int main(){
    ll n;cin >> n;
    vl d(n);
    set<ll> st;
    st.ins(0);
    rep(i,n){
        cin >> d[i];
        if(d[i]==0)cout<< 0 <<endl,exit(0);
        if(d[i]==12){
            if(!st.count(d[i])){
                st.ins(d[i]);
                continue;
            }
            else{
                cout<< 0 <<endl,exit(0);
            }
        }
        else{
            if(!st.count(d[i])){
                st.ins(d[i]);
                continue;
            }
            if(st.count(d[i])&&!st.count(24-d[i])){
                st.ins(24-d[i]);
                continue;
            }
            if(st.count(24-d[i])){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    set<ll> tt;
    ll cnt=0;
    for(auto p:st){
        if(st.count(p)&&st.count(24-p))tt.ins(p);
        else {
            if(cnt%2==0)tt.ins(p);
            else tt.ins(24-p);
            cnt++;
        }
    }
    ll pre,res=inf;
    for(auto p:tt){
        if(p)chmin(res,p-pre);
        pre=p;
    }
    chmin(res,24-*tt.rbegin());
    cout << res <<endl;
} 