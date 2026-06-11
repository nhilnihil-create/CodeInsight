#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
ll sub(ll a){
    if(a%4==0)return a;
    else if(a%4==1)return a^(a-1);
    else if(a%4==2)return a^(a-1)^(a-2);
    else return 0LL;
}
int main(void){
    ll a,b;
    cin>>a>>b;
    a=max(--a,0LL);
    cout<<(sub(a)^sub(b));
}
