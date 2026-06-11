#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) fort(int i=0;i<(n);i++)

int main(){
    ll n,m;
    cin>>n>>m;
    if(n==1 && m==1){
        cout<<1<<endl;
        return 0;
    }
    else if(n>=2 && m>=2){
        cout<<(n-2)*(m-2)<<endl;
        return 0;
    }
    else if(n==1 && m>1){
        cout<<m-2<<endl;
        return 0;
    }
    else if(m==1 && n>1){
        cout<<n-2<<endl;
        return 0;
    }
    else cout<<0<<endl;
}