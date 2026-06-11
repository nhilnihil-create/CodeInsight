#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

ll calc(ll x){
    ll ans;
    if(x%2==0){
        ans=(x/2)%2==0?0:1;
    }
    else {
        ans=calc(x-1)^(x-1);
    }
    return  ans;
}

int main(){
    ll a,b;cin >>a>>b;
    ll ans=calc(b+1)^calc(a);
    cout <<ans <<endl;
    return 0;
}
