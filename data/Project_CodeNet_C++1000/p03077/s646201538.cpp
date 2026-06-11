#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    vector<ll> abi(5);
    cin>>n;
    //ll t1=n,t2=0,t3=0,t4=0,t5=0,t6=0,ans=0;
    for(int i=0;i<5;i++){
        cin>>abi[i];
    }
    ll ans=0,now=0;
    for(int i=0;i<5;i++){
        if(n%abi[i]==0){
            now=n/abi[i];
            if(now>ans){
                ans=now;
            }
        }else{
            now=n/abi[i]+1;
            if(now>ans){
                ans=now;
            }
        }
    }
    cout<<ans+4<<endl;
}