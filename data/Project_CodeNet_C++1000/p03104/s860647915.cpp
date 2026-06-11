#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll XS(ll n){
    if(n%4==0){
        return n;
    }
    else if(n%4==1){
        return 1;
    }
    else if(n%4==2){
        return n+1;
    }
    else{
        return 0;
    }
}
int main(){
    ll a,b;
    cin>>a>>b;
    cout<<(XS(b)^XS(a-1))<<endl;
}