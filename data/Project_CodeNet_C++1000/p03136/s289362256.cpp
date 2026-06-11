#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,x,y,sum=0;
    cin>>n;
    int arr[n];
    for (i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    x= *max_element(arr,arr+n);
    y= sum-x;
    if (x<y)
        cout<<"Yes"<<endl;
    else 
        cout<<"No"<<endl;
}