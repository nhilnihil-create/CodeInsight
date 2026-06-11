#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,sum=0,s,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    m=*max_element(arr,arr+n);

    for(i=0;i<n;i++)
    {
        sum += arr[i];
    }
    s=sum-m;
    if(s>m)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}
