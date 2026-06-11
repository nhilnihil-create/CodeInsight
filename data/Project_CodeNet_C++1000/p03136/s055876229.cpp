#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int b;
    int temp=0;
    cin>>b;
    int a[b];
    long long int sum=0;
    for(int i=0;i<b;i++){
        cin>>a[i];
    }
    //cout<<a[0];
    for(int i=0;i<b-1;i++){
        for(int j=i+1;j<b;j++){
            if(a[i]<a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    //cout<<a[0]<<endl;
    for(int i=1;i<b;i++){
        sum=sum+a[i];
    }
    if(a[0]<sum){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
    return 0;
}
