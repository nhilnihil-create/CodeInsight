#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define ll long long
using namespace std;
int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    ll ans=(n-1)/(k-1);
    if(0==(n-1)%(k-1)){
        cout<<ans<<endl;
    }else{
        cout<<ans+1<<endl;
    }
    
    return 0;
}