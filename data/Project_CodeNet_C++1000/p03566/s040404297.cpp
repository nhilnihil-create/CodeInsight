#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    double s=0,n,v1[200001],v2[200001],T[200],V[200],ans=0;
    cin>>n;
    rep(i,n){
        cin>>T[i],s+=T[i];
        if(i>0) T[i]+=T[i-1];
    }
    rep(i,n) cin>>V[i];
    double t;
    int x=0;
    rep(i,2*s+1){
        t=double(i)/2;
        if(t==0) v1[i]=0;
        else v1[i]=min(v1[i-1]+0.5,V[x]);
        if(x<n-1&&t==T[x]) x++;
    }
    x=n-1;
    for(int i=2*s;i>=0;i--){
        t=double(i)/2;
        if(t==s) v2[i]=0;
        else v2[i]=min(v2[i+1]+0.5,V[x]);
        if(x>0&&t==T[x-1]) x--;
    }
    rep(i,2*s) ans+=(min(v1[i],v2[i])+min(v1[i+1],v2[i+1]))/4;
    cout<<setprecision(10)<<ans;
}