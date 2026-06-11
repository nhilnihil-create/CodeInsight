#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,x,y,X,Y,ans=INT_MAX;
    cin>>a>>b>>c>>x>>y;
    for(int i=0;i<=100000;i++){
        X=max(0,x-i);
        Y=max(0,y-i);
        int cost;
        cost=2*c*i+a*X+b*Y;

        ans=min(ans,cost);
        }
    cout<<ans<<endl;
    }
