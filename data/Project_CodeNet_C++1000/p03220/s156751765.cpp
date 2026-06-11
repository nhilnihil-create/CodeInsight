#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans=0;
    cin>>n;
    double t,a,m=1000000000;
    cin>>t>>a;
    for(int i=0;i<n;i++)
    {
        float x;
        cin>>x;
        if(abs(a-(t-(x*.006)))<m)
        {
            ans = i+1;
            m = abs(a-(t-(x*.006)));
        }
    }
    cout<<ans;

}
