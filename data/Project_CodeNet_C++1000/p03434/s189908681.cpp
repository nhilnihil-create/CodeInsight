#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    int i,alice=0,bob=0;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(i=0;i<n;i++)
    {
        if(i%2==0)
        alice+=arr[i];
        else
        {
            bob+=arr[i];
        }
        
    }

    cout<<abs(alice-bob)<<endl;
}