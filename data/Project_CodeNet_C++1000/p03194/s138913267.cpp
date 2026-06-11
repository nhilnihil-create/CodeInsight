#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    ll n,p;
    cin>>n>>p;
    for(ll i=pow(p,1.0/double(n))+1;i>0;i--){
        if(p%ll(pow(i,n))==0){
            cout<<i<<endl;
            return 0;
        }
    }
}
