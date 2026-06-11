#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

vector<ll> A(2005);
map<ll,ll> mp1,mp2;
ll N;
ll dfs(bool f, ll id, ll w, ll z){
    if(id == N){
        return abs(w-z);
    }
    if(mp1.count(id)){
        if(f==0){
            return mp1[id];
        }else{
            return mp2[id];
        }
    }
    ll MM = 0;
    ll mm = 1e18;
    REP(i,id,N){
        ll tmp = dfs(!f,i+1,z,A[i]);
        cmax(MM, tmp);
        cmin(mm, tmp);
    }
    mp1[id] = MM;
    mp2[id] = mm;
    if(f==0){
        return MM;
    }else{
        return mm;
    }
}

int main(){
    ll W,Z;
    cin >> N >> W >> Z;
    rep(i,N){
        cin >> A[i];
    }
    cout << dfs(0,0,W,Z) << endl;
}