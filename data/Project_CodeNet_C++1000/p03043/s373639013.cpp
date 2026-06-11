#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;

int main(){
    double N,K;
    cin>>N>>K;
    double ans=0,n=N;
    for(ll i=0;n>0;){
        if(K>n){
            i++;
            K/=2;
        }else{
            ans+=1.0/N*pow(0.5,i);
            n--;
        }
    }
    
    cout<<fixed<<setprecision(32)<<ans;
}