
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,arr[5];
    cin>>n;
    long long min=1000000000000000;
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
        if(arr[i]<=min)
        min=arr[i];
    }
    if(n<=min)
    {
        cout<<5;
        return 0;
    }
    n-=min;

long long x=ceil((1.0)*n/min)+5;
    cout<<x;
    
   
}
