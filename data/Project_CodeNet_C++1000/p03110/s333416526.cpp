#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(){
    ll n;
    cin>>n;
    ld ans=0;
    for(ll i=0;i<n;++i){
        ld x;
        string u;
        cin>>x>>u;
        if(u=="JPY"){
            ans+=x;
        }else{
            ans+=x*380000;
        }
    }
    cout<<setprecision(8)<<ans<<endl;
}