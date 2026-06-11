#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
#define vecout(V) for(int i=0;i<V.size();i++) {cout<<V[i]<<endl;}
typedef long long ll;

int main(void){
    ll n, k;
    cin>>n>>k;
    vector<ll> v;
    vector<ll> a;
    ll k2=k/2;
    for(ll i=1;i<=n;i++){
        if(i%k==0) v.push_back(i);
        else if(i%k==k2) a.push_back(i);
    }
    if(k%2==1){
        ll s=v.size();
        cout<<s*(s-1)*(s-2)+s*(s-1)*3+s<<endl;
    }
    else{
        ll s=v.size();
        ll t=a.size();
        cout<<s*(s-1)*(s-2)+s*(s-1)*3+s+t*(t-1)*(t-2)+t*(t-1)*3+t<<endl;
    }
    return 0;
}