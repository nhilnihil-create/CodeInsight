#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,m,sum=0;
    vector<int>v1,v2;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        v1.push_back(n);
    }
    for(int i=1;i<=t;i++)
    {
        cin>>m;
        v2.push_back(m);
    }
    for(int i=0;i<t;i++)
    {
        if(v1[i]-v2[i]>0)
            sum+=(v1[i]-v2[i]);
    }
    cout<<sum<<endl;
}
