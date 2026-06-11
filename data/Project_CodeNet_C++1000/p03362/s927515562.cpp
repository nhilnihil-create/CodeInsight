#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;

bool isprime(ll x){
    for(ll i=2; i*i<=x; i++){
        if(x%i==0)return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n; cin>>n;
    ll x = 9;
    while(n){
        if(isprime(x)){
            cout<<x<<" ";
            n--;
        }
        x+=10;
    }
    return 0;
}