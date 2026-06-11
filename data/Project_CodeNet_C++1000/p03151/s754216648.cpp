#define _LIBCPP_DEBUG 0
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef vector<int> vi;
typedef long long ll;



int main(){
    ll N,a[100010],b[100010],ato=0,bto=0;
    cin>>N;
    rep(i,0,N){
        cin>>a[i];
        ato+=a[i];
    }
    rep(i,0,N){
        cin>>b[i];
        bto+=b[i];
    }
    if(ato<bto){
        cout<<-1<<endl;
        return 0;
    }
    ll pl[100010],pite=0,mto=0,mcn=0;
    rep(i,0,N){
        if(a[i]>b[i]){
            pl[pite]=a[i]-b[i];
            pite++;
        }
        else if(a[i]<b[i]){
            mto+=b[i]-a[i];
            mcn++;
        }
    }
    if(mto==0){
        cout<<0<<endl;
        return 0;
    }
    sort(pl,pl+pite,greater<>());
    rep(i,0,pite){
        if(i!=0)pl[i]+=pl[i-1];
        if(mto<pl[i]){
            cout<<i+1+mcn<<endl;
            return 0;
        }
    }
    

    
}




