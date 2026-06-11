#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,m,l,r,c,i,j,mx,mn;
    cin>>n>>m;
    ll s[m],p[m];

    for(i=0;i<m;i++)
    {

        cin>>s[i]>>p[i];
        }sort(s,s+m);
        sort(p,p+m);
        for(i=0;i<m;i++)
        {
           if(p[0]-s[m-1]+1>0)c=p[0]-s[m-1]+1;
           else c=0;
        }
         cout<<c;}
