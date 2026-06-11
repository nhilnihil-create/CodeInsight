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
    cin >> N;
    vector<ll> P(N);
    rep(i,N){
        cin >> P[i];
    }
    vector<ll> A(N+1);
    rep(i,N){
        A[P[i]] = A[P[i]-1] + 1;
    }
    ll M = 1;
    rep(i,N){
        cmax(M, A[i+1]);
    }
    cout << N - M << endl;
}