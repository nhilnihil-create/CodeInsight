#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)


int main(){
    double n,k;
    cin>>n>>k;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    long double before=(n-1)/(k-1);
    int ans=ceil(before);
    cout<<ans<<endl;
}