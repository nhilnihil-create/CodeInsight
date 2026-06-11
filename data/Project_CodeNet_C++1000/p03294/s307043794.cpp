#include <bits/stdc++.h>
using namespace std;
int main()
{
    //Mo's Algorithm
    int n;
    cin>>n;
    int a[n+1];
    long long ans=0;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    	ans+=a[i]-1;
    }
    cout<<ans;

    return 0;
}

