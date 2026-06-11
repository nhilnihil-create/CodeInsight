#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n) for(ll i=0;i<(n);i++)
#define For1(i,n) for(ll i=1;i<(n);i++)
#define MOD 1000000007
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
double maxvel(double left,double right,double now,double v){
    if(now<left){
        return v+(left-now);
    }
    else if(now<right){
        return v;
    }
    else{
        return v+(now-right);
    }
}
int main(void){
    cout<<fixed<<setprecision(6);
    ll n,runtime=0;cin>>n;
    double ans=0,vel=0;
    vector<double> t(n+2),v(n+2),dt(n+2);
    t.at(n)=0;v.at(n)=0;t.at(n+1)=0;v.at(n+1)=0;dt.at(0)=0;
    For1(i,n+1){
        cin>>t.at(i);
        dt.at(i)=dt.at(i-1)+t.at(i);
    }
    For1(i,n+1)cin>>v.at(i);
    runtime=dt.at(n);dt.at(n+1)=dt.at(n);
    for(double i=0;i<=runtime;i+=0.5){
        double m=i;
        For1(j,n+2){
            m=min(m,maxvel(dt.at(j-1),dt.at(j),i,v.at(j)));
        }
        ans+=(vel+m)/4;
        vel=m;
    }
    cout<<ans<<endl;
}
