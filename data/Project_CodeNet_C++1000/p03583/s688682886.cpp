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
    REP(h,1,3501){
        REP(n,1,3501){
            ll a = N*h*n;
            ll b = 4*h*n - N*h - N*n;
            //cout << "a"<< endl;
            if(a >= b && b > 0 && a % b == 0){
                cout << h << " " << n << " " << a/b << endl;
                return 0;
            }
        }
    }
}