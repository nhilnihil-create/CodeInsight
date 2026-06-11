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
char g[330][330];
char ng[330][330];
int main(){
    int n;cin >> n;
    rep(i,n){
        rep(j,n){
            cin>>g[i][j];
        }
    }
    ll ans=0;
    rep(shift,n){
        rep(i,n){
            rep(j,n){
                ng[i][j]=g[i][(j+shift)%n];
            }
        }
        bool ok=true;
        rep(i,n){
            rep(j,n){
                if(ng[i][j]!=ng[j][i]) ok=false;
            }
        }
        if(ok){
            ans+=n;
        }
    }
    cout << ans << endl;
    return 0;
}