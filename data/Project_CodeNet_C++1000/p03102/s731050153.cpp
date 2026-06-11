#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,c,ans=0;
    cin>>n>>m>>c;
    int b[m]={};
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<m;j++)
        {
            int k;
            cin>>k;
            sum+=k*b[j];
        }
        if(sum+c>0)
            ++ans;
    }
    cout<<ans;
    return 0;
}

