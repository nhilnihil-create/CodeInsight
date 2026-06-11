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
    ll x,y,z,k;cin >> x >>y >>z >>k;
    vl a(x),b(y),c(z);
    rep(i,x)cin >> a[i];
    rep(i,y)cin >> b[i];
    rep(i,z)cin >> c[i];
    sort(all(a));sort(all(b));sort(all(c));
    rev(all(a));rev(all(b));rev(all(c));
    priority_queue<pl,vpl,less<pl>> que;
    unordered_map<ll,ll> ma;
    que.push({a[0]+b[0]+c[0],0});
    ma.ins({0,1});
    rep(i,k){
        pl p=que.top();
        ll num=p.se;
        que.pop();
        cout << p.fi <<endl;
        rep(i,3){
            ll d=pow(1000,i);
            if(ma.count(num+d))continue;
            ma.ins({num+d,1});
            ll qq=d+num;
            ll one=qq%1000;
            qq/=1000;
            ll two=qq%1000;
            qq/=1000;
            if(one>=x||two>=y||qq>=z)continue;
            que.push(mp(a[one]+b[two]+c[qq],num+d));
        }
    }
}