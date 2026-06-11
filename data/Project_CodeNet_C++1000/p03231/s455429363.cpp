#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll GCD(ll a, ll b){ return a ? GCD(b % a, a) : b; }
int main(){
    ll n,m;
    string s,t;
    cin>>n>>m>>s>>t;
    bool ok=true;
    if(n>m){
        swap(n,m);
        swap(s,t);
    }
    ll gcd=GCD(n,m);
    ll lcm=n/GCD(n,m)*m;
    ll nn =  n/gcd;
    ll mm =  m/gcd;
    for(int i=0; i<gcd; i++){
        if(s[i*nn]!=t[i*mm]) ok=false;
    }
    if(ok) cout<<n/GCD(n,m)*m<<endl;
    else cout<<-1<<endl;    
}