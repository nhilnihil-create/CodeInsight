#include <bits/stdc++.h>
using namespace std;
long di(long n,long num){
    if(n%2==0){
        return di(n/2,num+1);
    }
    else{
        return num;
    }
}
int main(){
    int n;
    cin>>n;
    long  a[n];
    long ans =99999999999;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        ans =min(ans,di(a[i],0));
    }
    cout<<ans<<endl;
}