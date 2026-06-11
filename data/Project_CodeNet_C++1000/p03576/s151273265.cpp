#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> x(N), y(N);
    rep(i,N){
        cin >> x[i] >> y[i];
    }
    vector<vector<ll>> S(N, vector<ll>(N));
    vector<vector<ll>> SS(N, vector<ll>(N));
    vector<vector<ll>> SX(N, vector<ll>(N));
    vector<vector<ll>> SY(N, vector<ll>(N));
    rep(yi,N)rep(xi,N)rep(i,N){
        if(y[yi] >= y[i] && x[xi] >= x[i]) S[yi][xi]++;
    }
    rep(yi,N)rep(xi,N)rep(i,N){
        if(y[yi] > y[i] && x[xi] > x[i]) SS[yi][xi]++;
    }
    rep(yi,N)rep(xi,N)rep(i,N){
        if(y[yi] > y[i] && x[xi] >= x[i]) SX[yi][xi]++;
    }
    rep(yi,N)rep(xi,N)rep(i,N){
        if(y[yi] >= y[i] && x[xi] > x[i]) SY[yi][xi]++;
    }
    //cout << "a" << endl;
    ll ans = ll(1e18)*4+1;
    rep(yh,N)rep(xh,N)rep(yl,N)rep(xl,N){
        ll ym = yl;
        ll yM = yh;
        ll xm = xl;
        ll xM = xh;
        if(y[ym] > y[yM])swap(ym,yM);
        if(x[xm] > x[xM])swap(xm,xM);
        ll cnt = S[yM][xM] - SY[yM][xm] - SX[ym][xM] + SS[ym][xm];
        if(cnt >= K){
            //cout << ll((y[yM] - y[ym])*(x[xM] - x[xm])) << endl;
            cmin(ans, ll((y[yM] - y[ym])*(x[xM] - x[xm])));
        }
    }
    cout << ans << endl;
}   