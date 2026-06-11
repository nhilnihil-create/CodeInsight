#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a7=1000000007;
ll inf=1000000000000000;
#define rep(i,l,r) for(ll i=l;i<=r;i++)

ll min(ll a,ll b){
    if(a<b)return a;
    return b;
}
ll max(ll a,ll b){
    if(a>b)return a;
    return b;
}

int main(){
    ll n,a,b;cin>>n>>a>>b;
    cout<<min(a,b)<<' '<<max(0,a+b-n)<<endl;
    
    return 0;
}
