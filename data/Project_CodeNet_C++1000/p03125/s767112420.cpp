#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll a,b;
    cin>>a>>b;
    if(b%a==0){
        cout<<a+b<<endl;
    }else{
        cout<<b-a<<endl;
    }
}