#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<62)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int n,k;
    cin >> n >> k;
    int x[n],y[n];
    rep(i,n)cin >> x[i] >> y[i];
    int xs[n],ys[n];
    rep(i,n)xs[i]=x[i];sort(xs,xs+n);
    rep(i,n)ys[i]=y[i];sort(ys,ys+n);
    ll ans = LINF;
    rep(ix,n)rep(jx,ix){
        int lx = xs[jx];
        int rx = xs[ix];
        rep(iy,n)rep(jy,iy){
            int ly = ys[jy];
            int ry = ys[iy];
            {
                int c = 0;
                rep(i,n){
                    if(x[i]<lx||x[i]>rx)continue;
                    if(y[i]<ly||y[i]>ry)continue;
                    c++;
                }
                if(c>=k){
                    ll s = (ll)(rx-lx)*(ll)(ry-ly);
                    chmin(ans,s);
                }
            }
        }
    }
    cout << ans << endl;
}