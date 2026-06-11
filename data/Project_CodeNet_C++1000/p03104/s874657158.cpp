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

ll func(ll x){ //f(x,0)
    if(x < 0) return 0;
    if(x % 2 == 1){
        ll tmp = (x+1)/2;
        return tmp % 2;
    }else{
        ll tmp = x/2;
        return (tmp%2) ^ x;
    }
}
int main(){
    ll A,B;
    cin >> A >> B;
    cout << (func(B) ^ func(A-1)) << endl;
}