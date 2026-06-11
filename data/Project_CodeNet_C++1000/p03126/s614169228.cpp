#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    ll n,m,k;
    cin>>n>>m;
    vector<ll> list;
    rep(i,m){
        list.push_back(0);
    }
    ll tmp;
    rep(i,n){
        cin>>k;
        rep(j,k){
           cin>>tmp;
           list[tmp]++; 
        }
    }
    ll ans=0;
    rep(i,m+1){
        // cout<<":"<<list[i]<<endl;
        if(list[i]==n)ans++;
    }

    cout<<ans<<endl;
}

