#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    cout<<((a&1 && !(b&1) || (!(a&1) && b&1))?"Borys\n":"Alice\n");    
}