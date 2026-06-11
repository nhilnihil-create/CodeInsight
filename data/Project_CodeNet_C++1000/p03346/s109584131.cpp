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
    vector<ll> P(N);
    rep(i,N){
        cin >> P[i];
    }
    vector<Pll> v(N);
    rep(i,N){
        v[i] = Pll(P[i], i+1);
    } 
    sort(v.begin(), v.end());
    ll cur = 0;
    ll M = 0;
    ll cnt = 0;
    rep(i,N){
        if(cur < v[i].se){
            cnt++;
            cmax(M,cnt);
        }else{
            cmax(M,cnt);
            cnt = 1;
        }
        cur = v[i].se;
    }
    cout << N - M << endl;
}