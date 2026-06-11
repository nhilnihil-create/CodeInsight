#include<bits/stdc++.h>
using namespace std;
int arr[100005];

int main(){

    int n,k,i,x,y,ans=INT_MAX,temp;
    cin>>n>>k;
    for(i=1; i<=n; i++)cin>>arr[i];
    for(i=k; i<=n; i++){
        if(arr[i-k+1]>0){
            temp=arr[i];
            ans=min(ans,temp);
        }
        else if(arr[i]<0){
            temp=abs(arr[i-k+1]);
            ans=min(ans,temp);
        }
        else{
            x=abs(arr[i-k+1]);
            y=arr[i];
            temp=max(x,y)+min(x,y)*2;
            ans=min(ans,temp);
        }
        ///cout<<i<<' '<<ans<<endl;
    }
    cout<<ans<<endl;

    return 0;
}