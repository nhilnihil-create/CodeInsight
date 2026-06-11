#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,x;
    cin>>n>>x;
    long long int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    long long int ans=0;
    long long int total=0;
    for(int i=0;i<n;i++)
    {
        total+=arr[i];
        if(total==x)
        {
            ans++;
            break;
        }
        if(total>x)
        {
            break;
        }
        ans++;
    }
    if(total<x)
    cout<<ans-1<<"\n";
    else
    cout<<ans<<"\n";
    
}