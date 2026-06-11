#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;
    cin>>n;
    while(n){
        ans+=n%10;
        n/=10;
    }
    if(ans==1)
        ans=10;
    cout<<ans;
    return 0;
}
