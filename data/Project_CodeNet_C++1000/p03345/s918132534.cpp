#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    ll a,b,c,k;
    cin>>a>>b>>c>>k;

    if(abs(a-b)>1000000000000000000) cout<<"Unfair"<<"\n";
    else if(k%2==0) cout<<a-b<<"\n";
    else cout<<b-a<<"\n";
    return 0;
}