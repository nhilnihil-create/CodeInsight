#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin>>n;
    vector<ll> abc(5);
    for(ll i=0;i<abc.size();i++){
        cin>>abc[i];
    }
    sort(abc.begin(),abc.end());
    ll ans=0;
    if(abc[0]>=n){
        ans=5;
    }else{
        ans=ceil(n/double(abc[0])+4);
    }
    cout<<ans<<endl;
    return 0;
}