#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,d,left,ans=0;
    cin>>n>>d>>left;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        for(int i=1;i<=d;i+=x)
        {
            ++ans;
        }
    }
    cout<<ans+left;
    return 0;
}

