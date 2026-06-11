#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    ll n,m;cin>>n>>m;
    ll p[11],c[11];
    rep(i,0,n)cin>>p[i]>>c[i];
    ll an=1e9;
    for(ll i=0;i<(1<<n);i++){
        ll sum=0,poi=0;
        bool fl[11];
        rep(j,0,n)fl[j]=0;
        rep(j,0,n){
            if(i&(1<<j)){
                sum+=p[j];
                poi+=100*p[j]*(j+1)+c[j];
                fl[j]=1;
            }
        }
        if(poi<m){
            for(int j=n-1;j>=0;j--){
                if(fl[j])continue;
                ll tmp=p[j];
                while(tmp!=1){
                    sum++;poi+=100*(j+1);
                    tmp--;
                    if(poi>=m)break;
                }
                if(poi>=m)break;
            }
        }
        if(poi>=m)an=min(an,sum);
    }
    cout<<an<<endl;
}

    







