#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;
    cin>>n;
    if(n%2==1){
        for(int i=1;(n-1)/2>=i;++i)
        ans+=2*i;
    }
    else{
        for(int i=1;n/2>=i;++i)
        ans+=2*i-1;
    }
    cout<<ans<<endl;
}