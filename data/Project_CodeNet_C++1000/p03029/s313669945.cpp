#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mod = 998244353;
const ll INF = 1001001001;
const ll LINF = 1001001001001001001;

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

int main(){
    ll a,p; cin >> a >> p;
    p += a*3;
    cout << p/2 << endl;
}