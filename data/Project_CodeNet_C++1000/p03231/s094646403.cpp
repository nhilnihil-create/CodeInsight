#include<iostream>
using namespace std;
using ll = long long;

ll gcd(ll x,ll y){
    return y==0 ? x : gcd(y,x%y);
}

ll lcm(ll x,ll y){
    return x/gcd(x,y)*y;
}

int main(){
    int n,m;
    string s,t;
    cin>>n>>m>>s>>t; 
    ll a=0,b=0;
    ll g=gcd(n,m);
    for(ll i=0;i<g;i++){
        if(s[i*n/g]!=t[i*m/g]){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<lcm(n,m)<<endl;
}