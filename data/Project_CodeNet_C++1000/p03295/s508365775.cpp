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
    ll N,M;
    cin >> N >> M;
    vector<ll> a(M), b(M);
    vector<Pll> P(M);
    rep(i,M){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        P[i] = Pll(b[i], a[i]);
    }
    sort(P.begin(),P.end());
    //vector<ll> memo(N,-1);
    ll z = -1;
    ll ans = 0;
    rep(i,M){
        if(P[i].se < z){
            continue;
        }else{
            z = P[i].fi;
            ans++;
        }
    }
    cout << ans << endl;
}