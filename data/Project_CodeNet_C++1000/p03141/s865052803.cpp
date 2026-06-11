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
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    ll sub=0;
    rep(i,n){
        sub-=b[i];
    }
    vl ab(n);
    rep(i,n){
        ab[i]=a[i]+b[i];
    }
    sort(ab.rbegin(),ab.rend());
    int time=(n+1)/2;
    ll ans=0;
    int i=0;
    while(time>0){
        ans+=ab[i];
        i+=2;
        time--;
    }
    ans+=sub;
    cout << ans << endl;
    return 0;
}