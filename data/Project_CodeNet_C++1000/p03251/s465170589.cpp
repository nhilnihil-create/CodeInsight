#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
using ll=long long;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int arr[a+3],ara[b+3];
    arr[0]=c;
    ara[0]=d;
    for(int i=1;i<=a;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+(a+1),greater<int>());
   // cout<<arr[0]<<endl;
    for(int i=1;i<=b;i++)
    {
        cin>>ara[i];
    }
     sort(ara,ara+(b+1));
     // cout<<ara[0]<<endl;
     if(arr[0]<ara[0])
     {
         cout<<"No War"<<endl;
     }
     else
     {
         cout<<"War"<<endl;
     }
     return 0;
}
