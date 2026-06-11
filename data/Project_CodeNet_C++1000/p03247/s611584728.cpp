#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

ll dist(ll x,ll y){
    return abs(x)+abs(y);
}

int main(){
    string s="RLUD";
    int n;cin>>n;
    ll x[n],y[n];
    bool odd=false,even=false;
    rep(i,n){
        cin>>x[i]>>y[i];
        if(abs(x[i]+y[i])%2)odd=true;
        else even=true;
    }
    if(even&&odd){
        cout<<"-1"<<endl;
        return 0;
    }
    ll a[40];
    int m;
    cout<<(m=39+even)<<endl;
    ll res=1LL<<38;
    rep(i,39){
        cout<<(a[i]=res)<<" ";
        res>>=1;
    }
    if(even)cout<<(a[39]=1);
    cout<<endl;
    rep(i,n){
        rep(j,m){
            ll mi=longinf;
            int ret=-1;
            if(dist(x[i]+a[j],y[i])<mi){mi=dist(x[i]+a[j],y[i]);ret=1;}
            if(dist(x[i]-a[j],y[i])<mi){mi=dist(x[i]-a[j],y[i]);ret=0;}
            if(dist(x[i],y[i]+a[j])<mi){mi=dist(x[i],y[i]+a[j]);ret=3;}
            if(dist(x[i],y[i]-a[j])<mi){mi=dist(x[i],y[i]-a[j]);ret=2;}
            cout<<s[ret];
            if(ret==0)x[i]-=a[j];
            if(ret==1)x[i]+=a[j];
            if(ret==2)y[i]-=a[j];
            if(ret==3)y[i]+=a[j];

        }
        cout<<endl;
    }
    return 0;
}