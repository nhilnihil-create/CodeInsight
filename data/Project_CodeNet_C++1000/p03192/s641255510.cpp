#include<bits/stdc++.h>
using namespace std;
int n,ans;
int main(){
    cin>>n;
    while(n){
        if(n%10==2) ans++;
        n/=10;
    }
    cout<<ans<<endl;
    return 0;
}