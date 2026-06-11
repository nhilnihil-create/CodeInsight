#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b;
ll f(ll a,ll b){
    ll A=4*a*b-n*b-n*a;
    ll B=n*a*b;
    if(A>0&&B>0&&B%A==0)return B/A;
    return 0;
}
int main(void){
    cin>>n;
    for(ll i=1LL;i<=3500;i++){
        for(ll j=1LL;j<=3500;j++){
            if(f(i,j)==0)continue;
            else{
                cout<<i<<" "<<j<<" "<<f(i,j)<<endl;
                return 0;
            }
        }
    }
}
