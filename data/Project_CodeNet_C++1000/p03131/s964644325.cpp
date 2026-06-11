#include<iostream>
using namespace std;
using ll = long long;

int main(){
    ll k,a,b;
    cin>>k>>a>>b;
    ll ans=1;
    if(b-a<=2) ans+=k;
    else{
        k-=a-1;
        ans=a;
        ans+=(b-a)*(k/2);
        if(k%2) ans++;
    }
    cout<<ans<<endl;
}