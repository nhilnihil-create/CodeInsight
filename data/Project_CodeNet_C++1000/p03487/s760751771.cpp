#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin>>n;
    map<ll,ll> amap;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        amap[a]++;
    }
    ll ans=0;
    for(const auto& item:amap){
        if(item.second>=item.first){
            ans+=item.second-item.first;
        }else{
            ans+=item.second;
        }
    }
    cout<<ans<<endl;
    return 0;
}