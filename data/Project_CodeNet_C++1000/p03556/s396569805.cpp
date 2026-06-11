#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long i,j,t,a,b,n,c,d,y,temp,m,r,sum,count,k,l,ans;
    t=1;
    // cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;;i++)
        {
            if(i*i<=n)continue;
            else break;
        }
        cout<<(i-1)*(i-1);
    }
}