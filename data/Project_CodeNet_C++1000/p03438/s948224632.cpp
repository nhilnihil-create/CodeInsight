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
    ll N;
    cin >> N;
    vector<ll> a(N), b(N);
    ll suma=0,sumb=0;
    rep(i,N){
        cin >> a[i];
        suma += a[i];
    }
    rep(i,N){
        cin >> b[i];
        sumb += b[i];
    }
    ll nop = sumb - suma;
    if(nop < 0){
        cout << "No" <<endl;
        return 0;
    }
    ll cnt=0;
    /*rep(i,N){
        cnt += max(0LL, a[i]-b[i]);
    }
    ll ta = cnt*2;*/
    rep(i,N){
        cnt += max(0LL, (b[i]-a[i]+1)/2);
    }
    if(cnt <= nop){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}