#include<iostream>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
const ll longinf=1LL<<60 ;
ll dist(ll x,ll y){
    return abs(x)+abs(y);
}

bool odd,even;
int main(){
    string s="RLUD";
    int n;cin>>n;
    ll x[n],y[n];
    rep(i,n){
        cin>>x[i]>>y[i];
        if(abs(x[i]+y[i])%2)odd=true;
        else even=true;
    }
    if(even&&odd){
        cout<<"-1"<<endl;
        return 0;
    }
    ll a[40],m=40;
    if(even)a[0]=1LL<<38;
    else a[0]=1LL<<39;
    rep(i,m-1)a[i+1]=(a[i]+1)/2;
    cout<<m<<endl;
    rep(i,m)cout<<a[i]<<" ";
    cout<<endl;
    rep(i,n){
        rep(j,m){
            ll mi=longinf;
            int ret=-1;
            if(dist(x[i]-a[j],y[i])<mi){mi=dist(x[i]-a[j],y[i]);ret=0;}
            if(dist(x[i]+a[j],y[i])<mi){mi=dist(x[i]+a[j],y[i]);ret=1;}
            if(dist(x[i],y[i]-a[j])<mi){mi=dist(x[i],y[i]-a[j]);ret=2;}
            if(dist(x[i],y[i]+a[j])<mi){mi=dist(x[i],y[i]+a[j]);ret=3;}
            if(ret==0)x[i]-=a[j];
            if(ret==1)x[i]+=a[j];
            if(ret==2)y[i]-=a[j];
            if(ret==3)y[i]+=a[j];
            cout<<s[ret];
        }
        cout<<endl;
    }
    return 0;
}