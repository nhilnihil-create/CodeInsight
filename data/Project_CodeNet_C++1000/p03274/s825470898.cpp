#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}

int main(){
    ll N, K;
    string S,T;
    cin >> N >> K;
    vector<ll> x(N),d(N);
    rep(i,N){
        cin >> x[i];
    }
    rep(i,N-1){
        d[i+1] = x[i+1] - x[i];
    }
    ll cur = 0;
    rep(i,K){
        cur += d[i];
    }
    ll M = cur + min(abs(x[0]), abs(x[0+K-1]));
    rep(i,N-K){
        cur -= d[i+1];
        cur += d[i+K];
        ll tmp = cur + min(abs(x[i+1]), abs(x[i+K]));
        cmin(M,tmp);
    }
    cout << M << endl;
    /*
    ll cur = 0;
    if(x[0] < 0 && x[K-1] < 0){
        cur -= x[0];
    }else if(x[0] < 0 && x[K-1] >= 0){
        cur = min(x[K-1] - 2*x[0], 2*x[K-1]-x[0]);
    }else{
        cur = x[K-1];
    }
    ll M = cur;
    rep(i,N-K+1){
        if(x[i] < 0){

        } && x[i+K] < 0){
            cur += x[i];
            cur -=
        }
        
    }
    cout << "Yes" << endl;*/
}