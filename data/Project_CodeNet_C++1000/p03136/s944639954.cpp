#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    cin>>arr[i];
    int maxindex=0;
    for(i=0;i<n;i++){
        if(arr[i]>arr[maxindex])
        maxindex=i;
    }
    int sum=0;
    for(i=0;i<n;i++){
        if(i!=maxindex)
        sum+=arr[i];
    }
    if(sum>arr[maxindex])
    cout<<"Yes";
    else
    cout<<"No";
    return 0;
}