#include<bits/stdc++.h>
using namespace std;
using ll =long long;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(i) i.begin(),i.end()
template<typename T=ll>
using v =vector<T>;
template<typename T=ll>
using vv = vector<v<T>>;
using p = pair<ll,ll>;
const ll INF = (ll)1e9;
template<typename T> T chmin(T &a,T b){a=min(a,b);}
template<typename T> T chmax(T &a,T b){a=max(a,b);}

int main(){
    ll a,b,c,k;
    cin >> a >> b >> c >> k;
    cout << (k%2==0?a-b:b-a);    

    return 0;
}