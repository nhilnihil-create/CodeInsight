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
    ll N;
    cin >> N;
    vector<ll> a(N),b(N);
    //ll suma=0;
    //ll sumb=0;
    rep(i,N){
        cin >> a[i];
        //suma += a[i];
    }
    rep(i,N){
        cin >> b[i];
        //sumb += b[i];
    }
    //ll nop = sumb - suma;*/
    ll cnta=0;
    ll cntb=0;
    rep(i,N){
        ll c = b[i] - a[i];
        if(c == 0){
            continue;
        }else if(c > 0){
            cntb += c / 2; 
        }else{
            cnta += -c;
        }
    }
    if(cntb >= cnta){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}