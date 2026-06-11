#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<=(n);i++)
using ll=long long;

int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    
    int min=INT_MAX;

    rep(i,200000){
        int z=i*c+a*max(0,x-(i/2))+b*max(0,y-(i/2));
        if(z<min)min=z;
    }
    
    cout<<min;
    return 0;
    }
