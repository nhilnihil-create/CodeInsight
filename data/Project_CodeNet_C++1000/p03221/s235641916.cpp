#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
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
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
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
    ll n,m;cin >> n >>m;
    vector<pair<pl,ll>> v(m);
    rep(i,m){
        cin >> v[i].fi.fi >> v[i].fi.se;
        v[i].se=i;
    }
    sort(all(v));
    vector<string> s(m);
    int k=1;
    rep(i,m){
        string res;
        if(i!=0){
            if(v[i].fi.fi!=v[i-1].fi.fi)k=1;
            else k++;
        }
        res+=to_string(k);
        while(res.size()<6){
            res='0'+res;
        }
        string form;
        int city=v[i].fi.fi;
        form+=to_string(city);
        while(form.size()<6){
            form='0'+form;
        }
        s[v[i].se]=form+res;
    }
    rep(i,m)cout << s[i] <<endl;
}