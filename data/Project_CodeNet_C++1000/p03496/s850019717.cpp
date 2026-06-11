#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    int n;
    cin>>n;
    int a[n],mn=INF,mx=-INF,s,t;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(mn>a[i]){
            mn=a[i];
            s=i;
        }
        if(mx<a[i]){
            mx=a[i];
            t=i;
        }
    }
    cout<<2*n-1<<endl;
    if(-mn<=mx){
        for(int i=0;i<n;i++){
            cout<<t+1<<" "<<i+1<<endl;
        }
        for(int i=1;i<n;i++){
            cout<<i<<" "<<i+1<<endl;
        }
    }
    else{
        for(int i=0;i<n;i++){
            cout<<s+1<<" "<<i+1<<endl;
        }
        for(int i=n-1;i>0;i--){
            cout<<i+1<<" "<<i<<endl;
        }
    }
}
