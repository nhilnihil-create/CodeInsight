#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define rep(i,x,n) for(int i=x;i<n;i++)
using ll=long long;

int main(){
    ll n,m;cin>>n>>m;
    if(n!=1) n-=2;
    if(m!=1) m-=2;
    cout<<n*m<<endl;
}