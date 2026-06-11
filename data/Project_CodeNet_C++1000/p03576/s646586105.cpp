#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    ll n,K;cin>>n>>K;
    ll x[55],y[55];
    rep(i,0,n)cin>>x[i]>>y[i];
    ll cn,an=8e18;
    rep(i,0,n){
        rep(j,0,n){
            rep(k,0,n){
                rep(m,0,n){
                    cn=0;
                    ll u=y[i],d=y[j],r=x[k],l=x[m];
                    if(d>u||l>r)continue;
                    rep(I,0,n){
                        if(d<=y[I]&&y[I]<=u&&l<=x[I]&&x[I]<=r)cn++;
                    }
                    if(cn==K){an=min(an,(u-d)*(r-l));}
                }
            }
        }
    }
    cout<<an<<endl;
}

    







