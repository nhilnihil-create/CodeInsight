#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x,y,ans=0;
    cin>>n>>x>>y;
    while(n--){
        int a,b;
        cin>>a>>b;
        if(a>=x&&b>=y)
            ans++;
    }
    cout<<ans;
}
