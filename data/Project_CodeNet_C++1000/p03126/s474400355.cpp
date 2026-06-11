#include <bits/stdc++.h>
using namespace std;

int a[50];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            int ia;
            cin>>ia;
            a[ia]++;
        }
    }

    int ans=0;

    for(int i=0;i<m;i++)
    {
        if(a[i+1]==n)ans++;
    }

    cout<<ans<<"\n";

    return 0;
}
