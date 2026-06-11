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
    vector<ll> x(N),y(N),h(N);
    rep(i,N){
        cin >> x[i] >> y[i] >> h[i];    
    }

    bool flag = true;
    rep(a,101){
        rep(b,101){
            ll L = 0;
            ll R = 1e18;
            while(L+1 < R){
                ll X = (L+R)/2;
                ll flag = -1;
                rep(i,N){
                    if(max(X - abs(x[i]-a) - abs(y[i]-b),ll(0)) < h[i]){
                        flag = 1;
                        break;
                    }else if(max(X - abs(x[i]-a) - abs(y[i]-b),ll(0)) > h[i]){
                        flag = 0;
                        break;
                    }
                }
                if(flag == -1){
                    cout << a << " " << b << " " << X << endl;
                    return 0;
                }else if(flag == 1){
                    L = X;
                }else{
                    R = X;
                }
            }
        }
    }
    //cout << cnt << endl;
}