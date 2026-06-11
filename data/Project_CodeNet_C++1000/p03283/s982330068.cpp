#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const ll INF = 1001001001;
const ll LINF = 1001001001001001001;

void prvec(vector<ll> vec){
    ll n = vec.size();
    rep(i,n) cout << i << " " << vec.at(i) << "\n";
}

void pr2d(vector<vector<ll>> vvec){
    ll h = vvec.size();
    ll w = vvec.at(0).size();
    rep(i,h){
        rep(j,w){
            cout << vvec.at(i).at(j) << " ";
        }
        cout << "\n";
    }
}

int main(){
    ll n , m , q; cin >> n >> m >> q;
    vector<vector<ll>> train(n+1,vector<ll>(n+1,0));
    rep(i,m){
        ll l,r; cin >> l >> r;
        train.at(l).at(r)++;
        train.at(r).at(l)++;
    }
    vector<vector<ll>> rui(n+1,vector<ll>(n+1,0));
    rep(i,n+1){
        for(int j=1;j<n+1;j++){
            rui[i][j] = rui[i][j-1] + train[i][j];
        }
    }
    rep(i,n+1){
        for(int j=1;j<n+1;j++){
            rui[j][i] += rui[j-1][i];
        }
    }
    //pr2d(rui);

    rep(i,q){
        ll a,b; cin >> a >> b;
        ll ans = rui[b][b] - rui[b][a-1] - rui[a-1][b] + rui[a-1][a-1];
        cout << ans/2 << "\n";
    }
    return 0 ;
}
