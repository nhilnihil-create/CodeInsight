#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    int ma=-10000000,mi=10000000,ma_p,mi_p;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>ma)ma=a[i],ma_p=i;
        if(a[i]<mi)mi=a[i],mi_p=i;
    }
    cout<<n*2-1<<endl;
    if(ma>-mi){
        for(int i=1;i<=n;i++)cout<<ma_p+1<<" "<<i<<endl;
        for(int i=1;i<n;i++)cout<<i<<" "<<i+1<<endl;
    }
    else{
        for(int i=0;i<n;i++)cout<<mi_p+1<<" "<<i+1<<endl;
        for(int i=n;i>1;i--)cout<<i<<" "<<i-1<<endl;
    }
    return 0;
}