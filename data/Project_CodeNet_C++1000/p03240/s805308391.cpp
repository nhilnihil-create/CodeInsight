#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

ll F(ll x, ll y, ll z, ll w, ll H){
    return max(H-abs(x-z)-abs(y-w),0LL);
}

int main(){
    ll N;
    cin >> N;
    vector<ll> x(N,0);
    vector<ll> y(N,0);
    vector<ll> h(N,0);
    ll t;
    for(ll i=0;i<N;i++){
        cin>>x[i]>>y[i]>>h[i];
        if(h[i]){t=i;}
    ;}
    for(ll i=0;i<=100;i++){
     for(ll j=0;j<=100;j++){
         ll H1=h[t]+abs(x[t]-i)+abs(y[t]-j);
         bool check=0;
         for(ll k=0;k<N;k++){
             if(F(x[k],y[k],i,j,H1)!=h[k]){check=1;break;}
         ;}
         if(!check){cout<<i<<" "<<j<<" "<<H1<<endl;return 0;}
     ;}
    ;}
    return 0;
}
