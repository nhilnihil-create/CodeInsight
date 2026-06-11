#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,a[102],k=0,l=0,cnt=0,x,n,m,c=200000000,b[102];
    int t;
    cin>>n>>t;
    for(i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(i=0;i<n;i++){
        if(b[i]<=t){c=min(c,a[i]);}
    }
    if(c==200000000){cout<<"TLE\n";}
    else{cout<<c<<endl;}



}

