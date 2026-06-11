#include<iostream>
using namespace std;
int main(){
    int n,a,t;
    cin>>n>>t>>a;
    int h;
    int ans,tmp1=2e9;
    for(int i=1;i<=n;i++){
        cin>>h;
        int d=(t*1000-h*6)-a*1000;
        if(d<0)d=-d;
        if(tmp1>d){
            tmp1=d;
            ans=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}