#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
int main(){
    int n,z,w,a[2005];
    cin>>n>>z>>w;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==1){
        cout<<llabs(a[n]-w);
    }
    else{
        cout<<max(llabs(a[n]-a[n-1]),llabs(a[n]-w));
    }
    return 0; 
}