#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
    long long int i,j,k,n,x,tot=0;
    vector<long long int>v,u;
    cin>>n;
    v.push_back(0);
    for(i=0;i<n;i++)
    {
        cin>>k;
        v.push_back(k);
    }
    v.push_back(0);
    for(i=1;i<=n+1;i++)
    {
        tot+=abs(v[i]-v[i-1]);
    }
    //cout<<tot<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<tot-abs(v[i]-v[i-1])-abs(v[i]-v[i+1])+abs(v[i-1]-v[i+1])<<endl;
    }
    return 0;
}
