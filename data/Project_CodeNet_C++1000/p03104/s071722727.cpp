#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll a,b;cin >>a>>b;
    ll d=b-a+1;
    ll f=0;
    ll tmp;
    ll ans=0;
    if(d%2==1){
        if(((d-1)/2)%2==1)f=1;
        if(a%2==1){
           ans=a^f;
        }
        else {
            ans=b^f;
        }
    }
    else {
        if(a%2==1){
            if(((d-2)/2)%2==1)f=1;
            ans=((a^b)^f);
        }
        else if(a%2==0){
            d/=2;
            if(d%2==1)ans=1;
            else ans=0;
        }
    }
    cout <<ans <<endl;
    return 0;
}