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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N), S(N+1);
    rep(i,N){
        cin >> A[i];
    }
    rep(i,N){
        S[i+1] = S[i] + A[i];
    }
    ll ans = 0;
    for(ll i = 40; i >= 0; i--){
        ll t = (1LL << i) + ans;
        ll cnt = 0;
        rep(j,N+1){
            REP(k,j+1,N+1){
                if(((S[k] - S[j]) & t) == t)cnt++;
            }
        }
        if(cnt >= K){
            ans = t;
            //cout << ans << endl;
        }
    }
    cout << ans << endl;
}