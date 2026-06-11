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
ld PI=3.14159265358979323846;

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> a(N), S(N+1), A;
    vector<vector<ll>> memo(31,vector<ll>(N+1));
    rep(i,N){
        cin >> a[i];
    }
    rep(i,N){
        S[i+1] = S[i] + a[i];
    }
    rep(i,N+1){
        REP(j,i,N+1){
            A.push_back(S[j]-S[i]);
        }
    }
    ll x = 0;
    rep(i,40){
        ll cnt = 0;
        ll tmp = (1LL << (39-i));
        rep(j,N*(N+1)/2){
            if((A[j] & (x+tmp)) == x + tmp){
                cnt++;
            }
        }
        if(cnt >= K){
            x += tmp;
        }
    }
    cout << x << endl;
}