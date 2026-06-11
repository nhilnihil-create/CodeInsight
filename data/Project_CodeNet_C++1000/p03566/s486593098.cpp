#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int k,tsum;
double s,d[40100],a,b[40100],ans,n,t[100];
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){cin>>t[i];tsum+=t[i];}
    for(int i=0;i<n;i++){
        cin>>a;
        for(int j=0;j<=t[i]*2;j++){
            if(j==0)d[k+j]=min(d[k+j],a);
            else d[k+j]=a;
        }
        k+=2*t[i];
    }
    d[2*tsum]=0;
    for(int i=0;i<2*tsum+1;i++){
        b[i+1]=min(b[i]+0.5,d[i+1]);
        //cout<<i<<d[i]<<endl;
    }
    b[2*tsum]=0;
    for(int i=2*tsum;i>0;i--)b[i-1]=min(b[i-1],min(b[i]+0.5,d[i-1]));
    for(int i=0;i<2*tsum;i++){
        //cout<<i<<" "<<b[i]<<endl;
        ans+=(b[i]+b[i+1]);
        //cout<<iac+1<<" "<<ans/4<<endl;
    }
    cout<<setprecision(10)<<ans/4<<endl;
}
