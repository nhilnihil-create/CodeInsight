#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int a,b,c; cin>>a>>b>>c;
    int p=min(a,c);
    int k=p;
    a=a-p;c=c-p;
    if(c<1)cout<<k+b;
    else{
        p=min(b,c); k=k+2*p; b=b-p; c=c-p;
        if(c<1)cout<<k+b;
        else cout<<k+1;
    }
}

