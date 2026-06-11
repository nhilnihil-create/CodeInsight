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
vi to[100010];
vi v(100010);
vi c(100010);
int p=0;
void dfs(int now,int from){
    v[now]=c[p++];
    for(auto next: to[now]){
        if(next==from) continue;
        dfs(next,now);
    }
}
int main(){
    int n;cin >> n;
    rep(i,n-1){
        int a,b;cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    rep(i,n) cin >> c[i];
    sort(c.rbegin(),c.rend());
    int ans=0;
    rep(i,n) ans+=c[i];
    ans-=c[0];
    //rep(i,n) cout << c[i] << endl;
    cout << ans << endl;
    dfs(1,-1);
    rrep(i,n){
        cout << v[i] << " ";
    }
    cout << endl;
}