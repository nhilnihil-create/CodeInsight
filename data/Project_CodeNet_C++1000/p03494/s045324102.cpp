#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        int d=0;
        while(x%2==0)
        {
            d++;
            x/=2;
        }
        ans=min(ans,d);
    }
    cout<<ans<<endl;
}