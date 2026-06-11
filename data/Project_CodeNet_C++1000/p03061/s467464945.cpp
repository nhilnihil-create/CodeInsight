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
    ll N;
    cin >> N;
    vector<ll> A(N),LS(N),RS(N);
    rep(i,N){
        cin >> A[i];
    }
    ll tmp = A[0];
    rep(i,N){
        tmp = __gcd(A[i], tmp);
        LS[i] = tmp;
    }
    tmp = A[N-1];
    rep(i,N){
        tmp = __gcd(A[N-1-i], tmp);
        RS[N-1-i] = tmp;
    }
    ll M = 0;
    rep(i,N){
        if(i == 0){
            cmax(M, RS[1]);
            continue;
        }else if(i == N-1){
            cmax(M,LS[N-2]);
            continue;
        }
        cmax(M, __gcd(LS[i-1], RS[i+1]));
    }
    cout << M << endl;
}