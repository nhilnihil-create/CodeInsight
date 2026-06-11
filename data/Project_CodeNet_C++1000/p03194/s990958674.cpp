#include <iostream>
#define ll long long
using namespace std;
typedef unsigned long long ull;
int main(void){
    // Your code here!
    ll n,p;
    cin>>n>>p;
    ll ans=1;
    for(ll i=2;i*i<=p;i++){
        if(n==1){
            ans=p;
            break;
        }
        ll count=0;
        while(p%i==0){
            count++;
            if(count==n){
                count=0;
                ans*=i;
            }
            p/=i;
        }
    }
    cout<<ans;
}
