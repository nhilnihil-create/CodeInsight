#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    ll n;
    cin>>n;
    vector<ll> v;
    vector<ll> c;

    ll tmp;
    rep(i,n){
        cin>>tmp;
        v.push_back(tmp);
    }
    rep(i,n){
        cin>>tmp;
        c.push_back(tmp);
    }

    ll ans=0;
    rep(i,n){
        ll p = v[i]-c[i];
        if(p>0)ans+=p;
    }
    cout<<ans<<endl;

}

