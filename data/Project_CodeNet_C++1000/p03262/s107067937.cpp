#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<string>;
using P =pair<int,int>;
const ll mod=1000000007;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

int main(){
    ll n;
    cin>>n;
    ll x;
    cin>>x;
    vector<ll> v(n+1);
    v[n]=x;
    for(ll i=0;i<n;++i)cin>>v[i];
    sort(v.begin(),v.end());
    ll gcdx=v[1]-v[0];
    for(ll i=1;i<n;++i){
        ll diff=v[i+1]-v[i];
        gcdx=__gcd(diff,gcdx);
    }
    cout<<gcdx<<endl;
}


