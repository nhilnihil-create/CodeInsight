#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

ll cal(ll x){
    if(x%2==0){
        return (x/2)%2;
    }
    else {
        return cal(x-1)^(x-1);
    }
}

int main(){
    ll a,b;cin >>a>>b;
    ll ans=cal(b+1)^cal(a);
    cout <<ans <<endl;
    return 0;
}