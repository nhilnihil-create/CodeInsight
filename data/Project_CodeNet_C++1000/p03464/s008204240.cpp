#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 998244353;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll K;
    cin >> K;
    vector<ll> A(K);
    rep(i,K){
        cin >> A[i];
    }
    ll L = 1;
    ll R = 1e18;
    while(L+1 < R){
        ll X = (L+R)/2;
        ll cur = X;
        rep(i,K){
            cur = ll(cur / A[i])*A[i];
        }
        if(cur > 2){
            R = X;   
        }else{
            L = X;
        }
    }
    ll M = L;
    L = 1;
    R = 1e18;
    while(L+1 < R){
        ll X = (L+R)/2;
        ll cur = X;
        rep(i,K){
            cur = ll(cur / A[i])*A[i];
        }
        if(cur < 2){
            L = X;
        }else{
            R = X;
        }
    }
    ll m = R;
    if(m <= M){
        cout << m << " " << M << endl;
    }else{
        cout << -1 << endl;
    }
}