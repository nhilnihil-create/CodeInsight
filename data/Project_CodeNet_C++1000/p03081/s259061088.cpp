#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef vector<ll> vi;
typedef vector<vi> vvi;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define REP(i,k,n) for(ll i=(ll)(k);i<(ll)(n);i++)
#define all(v) v.begin(),v.end()
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
const int mod=1e9+7;
const ll inf=1001001001001001;
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<'\n';}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}

int main(){
    int n,m;cin>>n>>m;
    string s;cin>>s;
    vector<char> t(m);
    vi v(m,1);
    rep(i,m){
        char c;cin>>t[i]>>c;
        if(c=='L')v[i]=-1;
    }
    int ok=n,ng=-1;
    while(ok-ng>1){
        int md=(ok+ng)/2;
        bool fall=false;
        int w=md;
        rep(i,m){
            if(s[w]==t[i])w+=v[i];
            if(w>=n)break;
            if(w<0){
                fall=true;
                break;
            }
        }
        if(fall)ng=md;
        else ok=md;
    }
    int l=ok;
    ok=-1,ng=n;
    while(ng-ok>1){
        int md=(ok+ng)/2;
        bool fall=false;
        int w=md;
        rep(i,m){
            if(s[w]==t[i])w+=v[i];
            if(w<0)break;
            if(w>=n){
                fall=true;
                break;
            }
        }
        if(fall)ng=md;
        else ok=md;
    }
    out(ok-l+1);
}