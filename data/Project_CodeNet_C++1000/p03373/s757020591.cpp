#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int sum=0;
    int ans=1e9;
    for(int i=0;i<=max(x,y);i++){
        sum=2*c*i+a*(max(x-i,0))+b*(max(0,y-i));
        if(ans>sum) ans=sum;
    }
    cout << ans << endl;
}
