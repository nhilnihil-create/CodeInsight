#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,k,x=0,i;
    int arr[1000];
    cin>>a>>b>>k;
    for (i=1;i<=min(a,b);i++)
    {
        if (a%i==0 && b%i==0)
        {
            arr[x]=i;
            x++;
        }
    }
    sort(arr,arr+x);
    reverse(arr,arr+x);
    cout<<arr[k-1]<<endl;
}