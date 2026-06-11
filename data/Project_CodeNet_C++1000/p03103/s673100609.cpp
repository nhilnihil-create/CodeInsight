
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    ll n, m;
    cin >> n >> m;
    
    map<ll,ll> store;
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        store[a] += b;
    }

    ll sum=0;
    //mapは要素を下位から上位へと並べている
    for(auto &x:store){
        if(x.second<m){
            sum += x.first*x.second;
            m -= x.second;
        }
        else{
            sum += x.first*m;
            break;
        }
    }
    cout << sum << endl;
    
}