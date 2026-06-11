#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int box[1000000];
void soinsuu(ll n){
  ll hoge=n;
    for(ll i=2;i*i<=n;i++){
        while(hoge%i==0){
            box[i]++;
            hoge/=i;    
        }
        if(hoge==1)break;
    } 
}
int main(){
    ll n,p;
    cin>>n>>p;
    if(n==1){
        cout<<p<<endl;
        return 0;
    }
    soinsuu(p);
    ll ans=1;
    for(ll i=2;i*i<=p;i++){
        while(box[i]>=n){
            ans*=i;
            box[i]-=n;
        }
    }
    cout<<ans<<endl;
}
