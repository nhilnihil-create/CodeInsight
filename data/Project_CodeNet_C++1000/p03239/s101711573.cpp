#include<bits/stdc++.h>

using namespace std;
int main(){
    int n,t,m,k=0,x=1008;
    cin>>n>>t;
    int r[n],b[n];
    for(int i=0 ;i<n;i++){
        cin>>r[i]>>b[i];
        if(b[i]<=t){

            if(r[i]<x){
                x=r[i];
                m=i;
                k=1;
            }
            if(r[i]==x && b[i]<b[m]){
                x=r[i];
                m=i;
                k=1;

            }
        }
    }
    if(k==0) cout<<"TLE"<<endl;
    else cout<<x<<endl;
return 0;
}

