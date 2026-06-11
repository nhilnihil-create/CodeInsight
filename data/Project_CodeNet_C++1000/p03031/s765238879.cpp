#include <bits/stdc++.h>
#define rep(i,n) for(long long i=0; i<n; i++)
#define Rep(i,n) for(long long i=1; i<n; i++)
#define ll long long
#include <math.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>


using namespace std;
#define PI acos(-1)
using P =pair<int,int>;

ll f(ll x,ll c,ll d){
    ll res =x;
    res -=x/c;
    res -=x/d;
    res+= x/lcm(c,d);
    return res;
}

int main(){
    ll a,b;
    cin>>a>>b;
    map<ll,vector<ll>>mp;
    ll tmp;
    ll c;
    rep(i,b){
        cin>>tmp;
        vector<ll>v(a);
        rep(j,tmp){
            cin>>c;
            v[c-1]=1;
        }
            mp[i]=v;
    }
    vector<ll>s(b);
    rep(i,b){
        cin>>s[i];
    }
    ll ans=0;
    for(ll i=0;i<(1<<a);i++){
        for(ll l=0;l<b;l++){
        tmp=0;    
            for(ll j=0;j<a;j++){
                    if(i>>j&1){
                    tmp+=mp[l][j];
                    }
            }
        if(tmp%2!=s[l])break;
        if(l==b-1)ans++;
        }    
    }
        cout<<ans<<endl;
}
