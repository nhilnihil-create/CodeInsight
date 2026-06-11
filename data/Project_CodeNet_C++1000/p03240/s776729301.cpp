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
    ll N,Mh=0;
    ll Mx,My;
    cin >> N;
    vector<ll> x(N),y(N),h(N);
    rep(i,N){
        cin >> x[i] >> y[i] >> h[i];
        cmax(Mh,h[i]);
        if(h[i] == Mh){
            Mx = x[i];
            My = y[i];
        }
    }
    rep(X,101){
        rep(Y,101){
            ll H = Mh + abs(X-Mx) + abs(Y-My);
            bool flag = true;
            rep(i,N){
                if(h[i] != max(H-abs(X-x[i])-abs(Y-y[i]), 0LL)){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout << X << " " << Y << " " << H << endl;
            }
        }
    }
}