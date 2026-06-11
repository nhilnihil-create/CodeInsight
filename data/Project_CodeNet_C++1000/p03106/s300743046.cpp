#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,k,arr[101],i,j=1;
    cin>>a>>b>>k;
    int mini=min(a,b);
    for(i=mini;i>=1;i--){
        if(a%i==0 && b%i==0){
            arr[j++]=i;
        }
    }
    for(j=1; ;j++){
            if(j==k){
                cout<<arr[j];
                break;
            }
    }
    return 0;
}
