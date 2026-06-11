#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int n,d[51];

int main(){
    cin>>n;
    rep(i,n)cin>>d[i];
    sort(d,d+n+1);
    for(int i=1;i<=n;i+=2)d[i]=24-d[i];
    sort(d,d+n+1);
    int ans=24;
    rep(i,n)ans=min(ans,d[i+1]-d[i]);
    cout<<min(ans,min(24-d[n],d[n]))<<endl;
}