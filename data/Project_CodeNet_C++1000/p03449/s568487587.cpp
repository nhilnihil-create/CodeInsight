#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,c=0,d,m; cin>>n;
    int arr[n],brr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++)cin>>brr[i];
    for(int i=0;i<n;i++){
        int j=i,d=0,m=0;
        for(int k=0;k<=j;k++){
            d=d+arr[k];
        }
        for(int l=j;l<n;l++){
            m=m+brr[l];
        }
        d=d+m;
        c=max(c,d);
    } cout<<c;
}
