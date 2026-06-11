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

vector<ll> pickdiv(ll n){
    vector<ll> res;
    for(ll i=1; i*i <=n;i++){
        if(n%i)continue;
        res.emplace_back(i);
        ll q = n/i;
        if(q != i){
            res.emplace_back(q);
        }
    }
    return res;
}

int main(){
    ll N;
    cin >> N;
    auto v = pickdiv(N);
    ll ans = 0;
    for(auto& q:v){
        ll a = N/q;
        if(a > q+1){
            ans += (a - 1);
        }
    }
    cout << ans << endl;
}