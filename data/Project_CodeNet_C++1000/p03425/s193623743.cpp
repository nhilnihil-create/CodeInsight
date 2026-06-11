#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    ll n;
    cin>>n;
    vector<string>ss(n);
    rep(i,n)cin>>ss[i];
    vector<ll>c(5,0);
    rep(i,n){
        if(ss[i][0]=='M')c[0]+=1;
        else if(ss[i][0]=='A')c[1]+=1;
        else if(ss[i][0]=='R')c[2]+=1;
        else if(ss[i][0]=='C')c[3]+=1;
        else if(ss[i][0]=='H')c[4]+=1;
    }
    ll cnt=0;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            for(int k=j+1;k<5;k++){
                cnt+=c[i]*c[k]*c[j];
            }
        }
    }
    cout<<cnt<<endl;
}
