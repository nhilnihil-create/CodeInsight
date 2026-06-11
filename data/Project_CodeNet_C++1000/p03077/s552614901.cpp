#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,a,ans=0,m;
    cin>>n;
    for(int i=1;i<=5;i++){
        cin>>a;
        if(i==1){
            m=a;
        }
        else if(a<m){
            m=a;
        }
    }
    if(n%m==0){
        ans=5+n/m-1;
    }
    else{
        ans=5+n/m;
    }
    cout<<ans<<endl;
    return(0);
}