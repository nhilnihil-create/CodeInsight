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

int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> a(M), b(M);
    vector<Pll> c(M);
    rep(i,M){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        c[i] = Pll(b[i], a[i]);
    }
    sort(c.begin(), c.end());
    ll prev = -1;
    ll ans = 0;
    rep(i,M){
        ll bb = c[i].fi;
        ll aa = c[i].se;
        if(aa <= prev){
            continue;
        }else{
            prev = bb-1;
            ans++;
        }
    }
    cout << ans << endl;
}