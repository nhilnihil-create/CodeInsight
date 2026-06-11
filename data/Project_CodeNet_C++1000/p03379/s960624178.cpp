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
    vector<ll> x(n);
    vector<ll> xsort(n);
    for(int i=0;i<n;i++){
        ll xi;
        cin>>xi;
        x[i]=xi;xsort[i]=xi;
    }
    ll mid=n/2;
    ll ans;
    sort(xsort.begin(),xsort.end());
    map<ll,ll> xsortmap;    
    ll last=-1;
    for(int i=0;i<n;i++){ 
        if(last==xsort[i]) continue;
        xsortmap[xsort[i]]=i;
        last=xsort[i];
    }
    for(int i=0;i<n;i++){
        ll index=xsortmap[x[i]];
        if(index<=mid-1){
            cout<<xsort[mid]<<" ";
        }else{
            cout<<xsort[mid-1]<<" ";
        }
    }    
    return 0;
}