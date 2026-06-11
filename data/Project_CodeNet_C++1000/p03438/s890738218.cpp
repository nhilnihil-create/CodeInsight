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
    ll N;
    cin >> N;
    vector<ll> a(N), b(N);
    ll suma = 0;
    ll sumb = 0;
    rep(i,N){
        cin >> a[i];
        suma += a[i];
    }
    rep(i,N){
        cin >> b[i];
        sumb += b[i];
    }
    if(suma > sumb){
        cout << "No" << endl;
        return 0;
    }
    ll M = sumb - suma;
    ll manua=0;
    ll manub=0;
    rep(i,N){
        if(a[i] == b[i]) continue;
        if(a[i] < b[i]){
            M -= (a[i] - b[i])/2 + ((a[i] - b[i])%2);
            manua += (a[i] - b[i])/2 + ((a[i] - b[i])%2);
            manub += ((a[i] - b[i])%2);
        }else{
            M -= b[i] - a[i];
            manub += b[i] - a[i];
        }
        if(M < 0){
            cout << "No" << endl;
            return 0;
        }
    }
    ll MM = sumb-suma;
    if(manua <= MM && manub <= MM && manua <= manub){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}