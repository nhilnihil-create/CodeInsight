#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,n,t,i,j,k,x,y,m,p,s,mx,mn;
    cin>>t;
    int ar[t],br[t],sum=0;
    for(p=0; p<t; p++)
    {
        cin>>ar[p];
    }
    for(p=0; p<t; p++)
    {
        cin>>br[p];
    }
    for(p=0;p<t;p++)
    {
        if(ar[p]>br[p])
        {
            sum=sum+(ar[p]-br[p]);
        }

    }
    cout<<sum<<endl;
}
