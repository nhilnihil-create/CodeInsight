#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    ll N;cin>>N;
    if(N==1||N==2){
        cout<<0<<endl;
        return 0;
    }
    ll ans=0;
    for(ll i=1;i*(i+1)<N;i++){
        if(N%i==0)ans+=N/i-1;
    }
    cout<<ans<<endl;
}





