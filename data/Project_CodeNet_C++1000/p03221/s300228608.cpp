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
    ll N,M;
    cin >> N >> M;
    vector<pair<Pll,ll>> v(M);
    vector<Pll> a(M);
    rep(i,M){
        ll p,y;
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;  
    }
    sort(v.begin(), v.end());
    ll prev = -1;
    ll ind = 0;
    rep(i,M){
        if(prev == v[i].first.first){
            ind++;
        }else{
            ind = 1;
        }
        a[v[i].second] = Pll(v[i].first.first,ind);
        prev = v[i].first.first;
    }
    rep(i,M){
        cout << setfill('0') << right << setw(6) << a[i].first;
        cout << setfill('0') << right << setw(6) << a[i].second;
        cout << endl;
    }
    //cout << cnt << endl;
}