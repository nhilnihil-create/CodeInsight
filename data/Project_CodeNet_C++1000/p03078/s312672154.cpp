#define ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
const ll INF=1001001001;
const ll LINF=1001001001001001001;
const ll D4[]={0,1,0,-1,0};
const ll D8[]={0,1,1,0,-1,-1,1,-1,0};
#define _overload3(_1,_2,_3,name,...) name
#define _rep2(i,n) for(ll i=0;i<(n);++i)
#define _rep3(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_rep3,_rep2)(__VA_ARGS__)
#define _repe2(i,n) for(ll i=0;i<=(n);++i)
#define _repe3(i,a,b) for(ll i=(a);i<=(b);++i)
#define repe(...) _overload3(__VA_ARGS__,_repe3,_repe2)(__VA_ARGS__)
#define _rrep2(i,n) for(ll i=(n)-1;i>=0;i--)
#define _rrep3(i,a,b) for(ll i=(b)-1;i>=(a);i--)
#define rrep(...) _overload3(__VA_ARGS__,_rrep3,_rrep2)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
template<class T>
bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>
bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
template<class T>
using pq=priority_queue<T,vector<T>,greater<T>>;

void solve();

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
}

ll x,y,z,k;
vl a,b,c;

void solve(){
    cin>>x>>y>>z>>k;
    a.resize(x);
    b.resize(y);
    c.resize(z);
    rep(i,x)cin>>a[i];
    rep(i,y)cin>>b[i];
    rep(i,z)cin>>c[i];
    sort(all(a),greater<>());
    sort(all(b),greater<>());
    sort(all(c),greater<>());

    priority_queue<pl> q;
    set<ll> added;
    q.emplace(a[0]+b[0]+c[0],0);
    added.insert(0);
    while(k--){
        pl p=q.top();q.pop();
        cout<<p.first<<endl;
        ll tx=p.second/1001/1001;
        ll ty=p.second/1001%1001;
        ll tz=p.second%1001;
        if(tx<x-1&&!added.count((tx+1)*1001*1001+ty*1001+tz)){
            q.emplace(a[tx+1]+b[ty]+c[tz],(tx+1)*1001*1001+ty*1001+tz);
            added.insert((tx+1)*1001*1001+ty*1001+tz);
        }
        if(ty<y-1&&!added.count(tx*1001*1001+(ty+1)*1001+tz)){
            q.emplace(a[tx]+b[ty+1]+c[tz],tx*1001*1001+(ty+1)*1001+tz);
            added.insert(tx*1001*1001+(ty+1)*1001+tz);
        }
        if(tz<z-1&&!added.count(tx*1001*1001+ty*1001+tz+1)){
            q.emplace(a[tx]+b[ty]+c[tz+1],tx*1001*1001+ty*1001+tz+1);
            added.insert(tx*1001*1001+ty*1001+tz+1);
        }
    }
}