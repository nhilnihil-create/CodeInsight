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

//75 = 75 or 25*3 or 15*5 or 5*5*3

int main(){
    ll n ; cin >> n;
    vector<ll> prefac(n+1,0);
    for(int i=2;i<=n;i++){
        ll x = i;
        for(int j=2;j<=n;j++){
            while(x%j==0){
                prefac.at(j)++;
                x/=j;
            }
        }
    }
    //prvec(prefac);

    ll cnt3 = 0, cnt5 = 0, cnt15 = 0, cnt25 = 0, cnt75 = 0;
    rep(i,n+1){
        if(prefac.at(i)>=2)cnt3++;
        if(prefac.at(i)>=4)cnt5++;
        if(prefac.at(i)>=14)cnt15++;
        if(prefac.at(i)>=24)cnt25++;
        if(prefac.at(i)>=74)cnt75++;
    }

    ll ans = cnt75 + (cnt25*(cnt3-1)) + (cnt15*(cnt5-1)) + (cnt5*(cnt5-1)/2)*(cnt3-2);
    cout << ans << endl;
    return 0;
}
