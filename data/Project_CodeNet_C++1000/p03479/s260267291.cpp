#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    ll x,y;
    cin>>x>>y;
    int cnt=0;
    for(ll i=x;i<=y;i*=2){
        cnt+=1;
    }
    cout<<cnt<<endl;
}