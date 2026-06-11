#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;



int main(){
    ll n,a,b,c;cin>>n>>a>>b>>c;
    ll l[10];
    rep(i,0,n)cin>>l[i];
    ll c1,c2,c3,x,y,z,tm,MN=1e9;
    for(ll i=0;i<(1<<2*n);i++){
        x=0,y=0,z=0;
        c1=0,c2=0,c3=0;
        tm=0;
        rep(j,0,n){
            if(!(i&(1<<(2*j)))&&i&(1<<(2*j+1))){
                c1++;
                x+=l[j];
            }
            else if(i&(1<<(2*j))&&!(i&(1<<(2*j+1)))){
                c2++;
                y+=l[j];
            }
            else if(i&(1<<(2*j))&&i&(1<<(2*j+1))){
                c3++;
                z+=l[j];
            }
        }
        if(c1*c2*c3==0)continue;
        tm+=(c1-1)*10;
        tm+=(c2-1)*10;
        tm+=(c3-1)*10;
        ll A=min(abs(a-x)+abs(b-y)+abs(c-z),abs(a-x)+abs(b-z)+abs(c-y));
        ll B=min(abs(a-y)+abs(b-x)+abs(c-z),abs(a-y)+abs(b-z)+abs(c-x));
        ll C=min(abs(a-z)+abs(b-y)+abs(c-x),abs(a-z)+abs(b-x)+abs(c-y));
        tm+=min(A,min(B,C));
        MN=min(MN,tm);
    }
    cout<<MN<<endl;
}
    







