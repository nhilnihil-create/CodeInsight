#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n,i;
    int a,flag=0;

    cin>>n;
    cin>>a;

    for(i=a;i>=0;i--){
        if((n-i)%500==0){
            flag=1;
            break;
        }

    }
    if(flag==1){cout<<"Yes"<<endl;}
    else {cout<<"No"<<endl;}
}
