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

void solve(){
    ll h,w;cin>>h>>w;
    vvl a(h,vl(w));
    rep(i,h)rep(j,w)cin>>a[i][j];

    vl y1,x1,y2,x2;
    rep(i,h*w-1){
        ll y=i/w,x=i%w;
        ll d=1;
        if(y%2)x=w-1-x,d=-1;
        if(a[y][x]%2==0)continue;
        y1.push_back(y);
        x1.push_back(x);
        if(d==1&&x==w-1||d==-1&&x==0){
            y2.push_back(y+1);
            x2.push_back(x);
            ++a[y+1][x];
        }else{
            y2.push_back(y);
            x2.push_back(x+d);
            ++a[y][x+d];
        }
    }

    ll n=y1.size();
    cout<<n<<endl;
    rep(i,n){
        cout<<y1[i]+1<<' '<<x1[i]+1<<' '<<y2[i]+1<<' '<<x2[i]+1<<endl;
    }
}