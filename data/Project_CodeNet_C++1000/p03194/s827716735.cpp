#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep1(n) rep2(i,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
ll zyo(ll a,ll b){
    if(b==0)return 1;
    else{
    a=a*zyo(a,b-1);
    return a;
    }
}
int main(){
    ll n,p,q;
    cin>>n>>p;
    q=p;
    ll memo;
    ll ans=1;
    if(n==1)cout <<p<<endl;
    else {
    while(p%2==0){
        p/=2;
        memo++;
    }
    if(memo>=n)ans=ans*zyo(2,memo/n);
    memo=0;
    for(ll i=3;i*i<=p;i+=2){
        while(p%i==0){
            memo++;
            p/=i;
        }

        if(memo>=n)ans=ans*zyo(i,memo/n);
        memo=0;
    }
    cout<<ans<<endl;
    }

}