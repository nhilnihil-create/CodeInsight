#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    long double n,m;
    cin>>n>>m;
    ll time=1900*m+(n-m)*100;
    long double p=pow(0.5,m);
    cout<<time/p<<endl;
}