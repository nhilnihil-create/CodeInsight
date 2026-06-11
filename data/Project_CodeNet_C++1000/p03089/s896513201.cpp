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
    string S,T;
    cin >> N;
    vector<ll> b(N),v;
    rep(i,N){
        cin >> b[i];
    }
    rep(i,N){
        rep(j,b.size()){
            if(b[b.size()-1-j] == ll(b.size())-j){
                b.erase(b.begin()+b.size()-1-j);
                v.push_back(b.size()-j+1);
                break;
            } 
        }
    }
    if(b.size() > 0){
        cout << -1 << endl;
    }else{
        rep(i,N){
            cout << v[N-1-i] << endl;
        }
    }
}