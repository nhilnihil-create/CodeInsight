#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[m+1]={};
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x;
        for(int j=0;j<x;j++)
        {
            cin>>y;
            ++a[y];
        }
    }
    int ans=0;
    for(int i=0;i<=m;i++)
        if(a[i]==n) ++ans;
    cout<<ans;
    return 0;
}

