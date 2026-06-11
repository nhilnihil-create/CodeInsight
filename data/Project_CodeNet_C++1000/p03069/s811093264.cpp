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

void rle(string s,vector<char> &cha,vector<ll> &num){
    ll a=0,cnt=0;
    string t;char x=s[0];
    while(a<s.size()){
        if(x==s[a])cnt++;
        else{
            cha.pb(x);num.pb(cnt);
            x=s[a];cnt=1;
        }
        a++;
    }
    cha.pb(x);num.pb(cnt);
}

int main(){
    ll n;cin >> n;
    string s;cin >> s;
    vl num;vector<char> c;
    rle(s,c,num);
    if(c[0]=='.')num[0]=0;
    if(*c.rbegin()=='#')*num.rbegin()=0;
    ll w=0,b=0;
    rep(i,c.size()){
        if(c[i]=='#')b+=num[i];
        else w+=num[i];
    }
    ll ans=w;
    ll cnt=0;
    rep(i,c.size()){
        if(c[i]=='#'&&i!=c.size()-1){
            w-=num[i+1];
            cnt+=num[i];
            chmin(ans,w+cnt);
        }
    }
    cout << ans <<endl;
}