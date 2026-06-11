#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

void f(ll &a,ll x,ll g){
    ll d=g-x;
    if(d>0){
        ll cost=(d%2==1)?2:0;
        a+=d/2+cost;
    }
    else a+=-d;
}

int main(){
   ll a,b,c;cin >>a>>b>>c;
   ll ans=INF;
    for (int i = 0; i <=100; ++i) {
        ll now=0;
        f(now,a,i);
        f(now,b,i);
        f(now,c,i);
//        cout <<i <<" "<<now<<endl;
        ans=min(ans,now);
    }
    cout <<ans <<endl;
   return 0;
}