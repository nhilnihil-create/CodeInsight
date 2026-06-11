#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;

ll soin[100];


int main(){
    ll n;cin>>n;

    rep(i,1,n+1){
        ll I=i;
        for(ll j=2;j*j<=i;j++){
            while(I%j==0){
                I/=j;
                soin[j]++;
            }
        }
        if(I!=1)soin[I]++;
    }
    ll an=0;
    ll c7=0,c24=0,c14=0,c4=0,c2=0;
    rep(i,0,100){
        if(soin[i]>=74)c7++;
        if(soin[i]>=24)c24++;
        if(soin[i]>=14)c14++;
        if(soin[i]>=4)c4++;
        if(soin[i]>=2)c2++;
    }
    an+=c7;
    an+=c24*(c2-1);
    an+=c14*(c4-1);
    an+=c4*(c4-1)/2*(c2-2);
    cout<<an<<endl;
}
    







