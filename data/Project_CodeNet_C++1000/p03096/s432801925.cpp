#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const ll INF = 1001001001;
const ll LINF = 1001001001001001001;
ll n ;
vector<ll> c(0);
vector<ll> mem;
vector<vector<ll>> place(200001,vector<ll>(0));

void prvec(vector<ll> vec){ //for debug
    ll n = vec.size();
    cout << "------------------------------------\n" ;
    rep(i,n) cout << i << " " << vec.at(i) << "\n";
    cout << "------------------------------------\n" ;
}

void pr2d(vector<vector<ll>> vec){ // for debug
    ll h = vec.size();
    ll w = vec.at(0).size();
    cout << "------------------------------------\n" ;
    rep(i,h){
        rep(j,w){
            cout << vec.at(i).at(j) << " ";
        }
        cout << "\n";
    }
    cout << "------------------------------------\n" ;
}

ll f(ll x){
    if(x==n-1) return 1;
    if(mem.at(x)!=-1) return mem.at(x);
    ll ret = f(x+1);
    ll y = c.at(x);
    ll add = 0;
    auto it = upper_bound(place.at(y).begin(),place.at(y).end(),x);
    if(it!=place.at(y).end()) add = f(*it);
    ret = (ret + add)% mod;
    mem.at(x) = ret;
    return ret;
}


// main starts here

int main(){
    cin >> n;
    ll prev = INF;
    rep(i,n){
        ll a; cin >> a;
        if(a!=prev) c.emplace_back(a);
        prev = a;
    }
    n = c.size();
    rep(i,n) place.at(c.at(i)).emplace_back(i);
    mem.resize(n,-1);
    cout << f(0) << endl;
}
