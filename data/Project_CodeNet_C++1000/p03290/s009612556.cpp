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
    ll D,G;
    cin >> D >> G;
    vector<ll> p(D), c(D);
    rep(i,D){
        cin >> p[i] >> c[i];
    }
    ll ans = 1e18;
    for(ll i = 0; i<(1LL << D); i++){
        ll sum = 0;
        ll nsol = 0;
        rep(j,D){
            if((i >> j) & 1LL){
                sum += (j+1)*100*p[j] + c[j];
                nsol += p[j];
            }
        }
        if(sum >= G){
            cmin(ans,nsol);
        }else{
            for(ll j=D-1;j>=0;j--){            
                if(!((i >> j) & 1LL)){
                    rep(k,p[j]){
                        sum += (j+1)*100;
                        nsol++;
                        if(sum >= G){
                            break;
                        }
                    }
                    break;
                }
            }
            if(sum >= G){
                cmin(ans,nsol);
            }
        }
    }
    cout << ans << endl;
}