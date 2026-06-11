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
    ll n , c;  cin >> n >> c;
    vector<vector<ll>> d(c,vector<ll>(c,-1));
    rep(i,c) rep(j,c) cin >> d.at(i).at(j);
    vector<vector<ll>> b(n,vector<ll>(n,0));
    rep(i,n) rep(j,n){
        cin >> b.at(i).at(j);
        b.at(i).at(j)--;
    }

    vector<ll> zero(c,0),one(c,0),two(c,0);
    rep(i,n){
        rep(j,n){
            ll x = b.at(i).at(j);
            if((i+j)%3 == 0){
                zero.at(x)++;
            }else if((i+j)%3 == 1){
                one.at(x)++;
            }else{
                two.at(x)++;
            }
        }
    }

    ll minimum_cost = INF;

    for(int i=0;i<c;i++){ //zero
        for(int j=0;j<c;j++){ //one
            if(i==j) continue;
            for(int k=0;k<c;k++){ //two
                if(i==k || j==k) continue;
                ll cost = 0;

                for(int ii=0;ii<c;ii++){
                    if(ii==i) continue;
                    cost += zero.at(ii) * d.at(ii).at(i);
                }
                for(int jj=0;jj<c;jj++){
                    if(jj==j) continue;
                    cost += one.at(jj) * d.at(jj).at(j);
                }
                for(int kk=0;kk<c;kk++){
                    if(kk==k) continue;
                    cost += two.at(kk) * d.at(kk).at(k);
                }

                minimum_cost = min(minimum_cost,cost);
            }
        }
    }

    cout << minimum_cost << endl;
    return 0;
}