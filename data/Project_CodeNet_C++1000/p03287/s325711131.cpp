#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    int amari[n+1];
    amari[0]=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        amari[i+1]=(amari[i]+a[i])%m;
    }
    sort(amari,amari+n+1);
    long long ans=0;
    long long x=1;
    for(int i=0;i<n;i++){
        if(amari[i]==amari[i+1])x++;
        else{
            ans+=x*(x-1)/2;
            x=1;
        }
    }
    cout<<ans+x*(x-1)/2<<endl;
    return 0;
}