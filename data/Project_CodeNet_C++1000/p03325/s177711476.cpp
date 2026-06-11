#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        while(x%2==0)ans++,x/=2;
    }
    cout<<ans<<endl;
}