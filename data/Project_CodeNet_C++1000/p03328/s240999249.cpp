#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,ans=0;
    cin>>a>>b;
    int diff=max(a,b)-min(a,b);
    for(int i=1;i<=diff;i++)
    ans+=i;
    cout<<ans-max(a,b)<<endl;
}