#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    // Your code here!
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(0,i,n)cin>>a[i];
    sort(a.rbegin(),a.rend());
    ll A=0,B=0;
    rep(0,i,n){
        if(i%2==0)A+=a[i];
        else B+=a[i];
    }
    cout<<A-B;
}