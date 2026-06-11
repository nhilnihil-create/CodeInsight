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
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N), S(N+1), B(N+1);
    rep(i,N){
        cin >> A[i];
    }
    rep(i,N){
        S[i+1] = S[i] + A[i];
    }
    map<ll,ll> mp;
    rep(i,N+1){
        mp[S[i]%M]++;
    }
    ll ans = 0;
    for(auto& e:mp){
        ans += e.second*(e.second-1)/2;
    }
    cout << ans << endl;
}