#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,x,a,count=0,pount=0;
    cin>>n>>m>>x;
    for(int i=0;i<m;i++)
    {
        cin>>a;
        if(a>x && a<n+1)
        {
            count++;
        }
        if(a<x)
        {
            pount++;
        }
    }
    
    if(count>pount)
    cout<<pount<<"\n";
    else
    cout<<count<<"\n";
    
    return 0;
}