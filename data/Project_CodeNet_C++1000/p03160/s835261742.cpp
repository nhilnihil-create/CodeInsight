#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int h[n];
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    int arr[n+1];
    arr[0]=0;
    arr[1]=0;
    arr[2]=abs(h[1]-h[0]);
    for(int i=3;i<n+1;i++){
        int x=abs(h[i-1]-h[i-2]);
        int y=abs(h[i-1]-h[i-3]);
        arr[i]=min(arr[i-1]+x,arr[i-2]+y);     
    }
    cout<<arr[n]<<endl;
    return 0;
    
}
