#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long ;
int main()
{
    int n,m;
    cin>>n>>m;
    int L=0,R=n;
    rep(i,m){
        int l,r;
        cin>>l>>r;
        L=max(L,l);
        R=min(R,r);
    }
    if(R-L>=0) cout<<R-L+1;
    else cout<<"0";
}