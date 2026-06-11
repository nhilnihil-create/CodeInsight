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
    ll N,M,Q;
    cin >> N >> M >> Q;
    vector<vector<ll>> S(N+1, vector<ll>(N+1));
    ll l,r;
    rep(i,M){
        cin >> l >> r;
        l--;r--;
        S[l+1][r+1]++;
    }
    vector<ll> p(Q), q(Q);
    rep(i,Q){
        cin >> p[i] >> q[i];
        p[i]--;q[i]--;
    }
    rep(i,N){
        rep(j,N){
            S[i+1][j+1] += S[i+1][j];
        }
    }
    rep(j,N){
        rep(i,N){
            S[i+1][j+1] += S[i][j+1];
        }
    }
    rep(i,Q){
        cout << S[q[i]+1][q[i]+1] + S[p[i]][p[i]] - S[q[i]+1][p[i]] - S[p[i]][q[i]+1] << endl;
    }
}