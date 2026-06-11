#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,flag=0,count=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    while(flag!=1){
        for(i=0;i<n;i++){
            if(a[i]%2!=0){
                flag++;
                break;
            }
            a[i]=a[i]/2;
        }
        count++;
    }
    cout<<count-1;

}