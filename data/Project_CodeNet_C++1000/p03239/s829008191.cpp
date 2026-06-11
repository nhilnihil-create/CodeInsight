#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,t;
    int minc=1000;
    bool can=false;
    cin>>n>>t;
    for(int i=0;i<n;i++){
        int c,tt;
        cin>>c>>tt;
        if(tt<=t){
            minc=min(minc,c);
            can=true;
        }
    }

    if(can) cout<<minc<<endl;
    else cout<<"TLE"<<endl;


    return 0;
}