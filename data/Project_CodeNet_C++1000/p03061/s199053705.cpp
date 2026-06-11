#include <bits/stdc++.h>
//#include <atcoder/all>
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
//using namespace atcoder;

int main(){
    ll N;
    //cout << __gcd(0,27) << endl;
    cin >> N;
    vector<ll> A(N), L(N+1), R(N+1);
    rep(i,N){
        cin >> A[i];
    }
    rep(i,N){
        L[i+1] = __gcd(L[i], A[i]);
    }
    for(ll i=N-1;i>=0;i--){
        R[i] = __gcd(R[i+1], A[i]);
    }
    ll ans = 0;
    rep(i,N){
        cmax(ans, __gcd(L[i], R[i+1]));
    }
    cout << ans << endl;
}