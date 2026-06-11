#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll a,b;
    cin>>a>>b;
    cout<<max(a+b,max(a-b,a*b));
}
