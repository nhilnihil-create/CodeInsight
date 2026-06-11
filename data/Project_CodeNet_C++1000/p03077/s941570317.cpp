#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    ll n;
    cin>>n;
    vector<ll>tp(5);
    rep(i,5)cin>>tp[i];
    sort(tp.begin(),tp.end());
    ll k=tp[0];
    ll ans=0;
    ans+=4;
    if(n<k){
        cout<<5<<endl;
        return 0;
    }
    ll hito=n/k;
    if(n%k!=0)hito+=1;
    ans+=hito;
    cout<<ans<<endl;
    

}