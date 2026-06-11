#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
    int n,sum=0;
    cin>>n;
    int arr[n+1],arr1[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>arr1[i])
        {
            sum=sum+(arr[i]-arr1[i]);
        }
    }
    cout<<sum<<endl;
}
