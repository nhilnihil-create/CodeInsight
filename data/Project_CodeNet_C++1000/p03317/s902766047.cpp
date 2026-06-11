#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    int pos;
    for(int i=0;i<n;i++)
    {cin>>arr[i];
    if(arr[i]==1)
    pos=i/(k-1);
    }
    int s=0;
    while(s<pos*(k-1))
    {
        s++;
    }
    pos=s;
    int cnt=0;
    int z=pos;
    while(z<n)
    {
        if(z==n-1)
        break;
        cnt++;
        z+=(k-1);
        
    }
    z=pos;
    while(z>=0)
    {if(z==0)
    break;
        cnt++;
        z-=(k-1);
    }
    
    cout<<cnt<<endl;
}
