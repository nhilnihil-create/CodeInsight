#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N,C;
    cin >> N >> C;
    vector<ll> s(N), t(N), c(N);
    vector<vector<ll>> tvp(C, vector<ll>(100005));
    rep(i,N){
        cin >> s[i] >> t[i] >> c[i];
        c[i]--;
        tvp[c[i]][s[i]]++;
        tvp[c[i]][t[i]]--;
    }
    //PR(tvp[0],20);
    //PR(tvp[1],20);
    vector<ll> v(100005);
    rep(i,C){
        rep(j,100004){
            if(tvp[i][j] > 0){
                v[j] += tvp[i][j];
            }else{
                v[j+1] += tvp[i][j];
            }
        }
    }
    //PR(v,100005);
    rep(i,100005){
        v[i+1] += v[i];
    }
    ll ans = 0;
    rep(i,100005){
        cmax(ans, v[i]);
    }
    cout << ans << endl;
}