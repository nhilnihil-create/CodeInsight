#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mod = 1000000007;
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
    ll n ; cin >> n;
    vector<ll> prime(55555,1);
    prime.at(0) = 0;
    prime.at(1) = 0;
    prime.at(2) = 1;
    for(int i=2;i<=55554;i++){
        if(!prime.at(i)) continue;
        ll x = i;
        while(true){
            x+=i;
            if(x>55554) break;
            prime.at(x) = 0;
        }
    }
    //prvec(prime);
    ll cnt = 0;
    rep(i,55554){
        if(i%5!=1) continue;
        if(prime.at(i)){
            cout << i;
            cnt++;
        }else{
            continue;
        }
        if(cnt==n) break;
        cout << " ";
    }
    cout << endl;
    return 0;
}