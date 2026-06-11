#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<cmath>

using namespace std;
using ll = long long;

int main(){
    ll k,a,b;cin>>k>>a>>b;
    ll ans=1;
    ll coin=0;
    if(b-a>1){
        for(ll i=0;i<k;i++){
            if(coin>0){
                ans+=b;
                coin--;
            }
            else if(i!=k-1&&ans>=a){
                ans-=a;
                coin++;
            }
            else ans++;
        }
    }
    else ans += k;

    cout<<ans<<endl;
}
