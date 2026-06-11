#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    ll n; cin>>n;
    ll f=0;
    ll m=n;
    while(m>0){
        f+=m%10;
        m=m/10;
    }
    if(n%f==0){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    
}
