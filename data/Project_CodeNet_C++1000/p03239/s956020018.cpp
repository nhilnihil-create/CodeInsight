#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    ll n,t;
    cin>>n>>t;
    ll x,y;
    ll min=1001;
    rep(i,n){
        cin>>x>>y;
        if(y<=t){
            min=std::min(min,x);
        }
    }
    if(min==1001)cout<<"TLE"<<endl;
    else cout<<min<<endl;
}

