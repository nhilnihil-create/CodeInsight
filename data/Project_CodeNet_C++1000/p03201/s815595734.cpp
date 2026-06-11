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
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
int main(){
    int n;cin >> n;
    vl a(n);
    rep(i,n) cin >> a[i];
    multiset<ll> s;
    rep(i,n) s.insert(a[i]);
    ll ans=0;
    //cout << s.count(0) << endl;
    while(s.size()){
        ll x=*s.rbegin();
        s.erase(s.find(x));
        ll y;
        drep(i,32){
            ll sum=(1ll<<i);
            y=sum-x;
            if(s.count(y)>0) break;
            y=-1;
        }
        if(y!=-1){
            s.erase(s.find(y));
            ans++;
            //cout << x << " " << y << endl;
        }
    }
    cout << ans << endl;
    return 0;
}