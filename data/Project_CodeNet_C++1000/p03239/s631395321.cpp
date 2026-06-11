#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,i,c,x,mn=INT_MAX,f=1;
    cin>>n>>t;
    int a[n+2],b[n+2];
    for(i=0; i<n; i++)
    {
        cin>>a[i]>>b[i];

    }
    for(i=0; i<n; i++)
    {
        if(b[i]<=t)
        {
            mn=min(mn,a[i]);
            f=0;
        }

    }
    if(f==0)
        cout<<mn<<endl;
   else
        cout<<"TLE"<<endl;

}
