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
/*
i) N=2M

*/
int main(){
    ll N;
    cin >> N;
    vector<Pll> v;
    //set<Pll> memo;
    if(N%2==0){
        REP(i,1,N+1){
            REP(j,i+1,N+1){
                if(i+j==N+1)continue;
                v.push_back(Pll(i,j));
            }
        }
    }else{
        REP(i,1,N){
            REP(j,i+1,N){
                if(i+j==N)continue;
                v.push_back(Pll(i,j));
            }
            v.push_back(Pll(i,N));
        }
    }
    cout << v.size() << endl;
    for(auto& p:v){
        cout << p.fi << " " << p.se << endl;
    }
}