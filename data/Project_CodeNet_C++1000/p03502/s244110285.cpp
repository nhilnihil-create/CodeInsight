#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    string n;
    cin>>n;
    ll f=0;
    rep(0,i,n.length())f+=n[i]-'0';
    ll n0=atoi(n.c_str());
    if(n0%f)cout<<"No";
    else cout<<"Yes";
}
