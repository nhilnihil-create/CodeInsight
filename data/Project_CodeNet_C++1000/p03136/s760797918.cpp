#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
#define pb push_back
int main(void){
    ll n;
    cin>>n;
    vector<ll>a(n);
    ll sum=0,M=0;
    rep(0,i,n){
        cin>>a[i];
        M=max(a[i],M);
        sum+=a[i];
    }
    sum-=M;
    if(M<sum){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}