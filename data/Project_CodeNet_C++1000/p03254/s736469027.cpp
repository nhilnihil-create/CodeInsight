#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x,i;
    cin>>n>>x;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);
    for(i=0;i<n;i++){
        x-=arr[i];
        if(x<0){
            break;
        }
    }
    if(x>0) 
      i--;
    cout<<i;
  return 0;
}
