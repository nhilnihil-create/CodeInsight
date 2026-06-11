#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;
    cin>>n;
    for(int i=0;i<9;i++){
        ans+=111;
        if(ans>=n){
            cout<<ans<<endl;
            break;
        }
    }
    return(0);
}