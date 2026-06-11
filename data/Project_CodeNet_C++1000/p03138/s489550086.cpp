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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    ll X = 0;
    for(ll i=40;i>=0;i--){
        X += (1LL << i);
        if(X > K){
            X -= (1LL << i);
            continue;
        }
        ll cnt = 0;
        rep(j,N){
            if((A[j] >> i) & 1LL) cnt++;
        }
        if(cnt > N/2){
            X -= (1LL << i);
        }
    }
    ll ans = 0;
    rep(i,N){
        ans += (X^A[i]);
    }
    cout << ans << endl;
}