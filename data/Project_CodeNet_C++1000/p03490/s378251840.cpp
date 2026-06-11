#include<bits/stdc++.h>
#define int long long
using namespace std;
 

bool dp1[8005][16005],dp2[8005][16005];

signed main()
{
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   
 
 
#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif    

    string a;
    cin>>a;
    int l,r;
    cin>>l>>r;
    int n=a.length();
    vector<int>x,y;
    int dis=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='F')
            dis++;
        else
        {
            if(x.size()==y.size())
            {
                x.push_back(dis);
                dis=0;
            }
            else
            {
                y.push_back(dis);
                dis=0;
            }
        }
    }
    if(a[n-1]!='T')
    {
        if(x.size()==y.size())
        {
            x.push_back(dis);
        }
        else
        {
            y.push_back(dis);
        }
    }
    int lim=8000;
    dp1[0][lim]=1;
    dp2[0][lim]=1;
    int sz=x.size();
    for(int i=0;i<sz;i++)
    {
        int tt=x[i];
        for(int j=0;j<=2*lim;j++)
        {
            if(j+tt<=2*lim && i>0)
               dp1[i+1][j]|=dp1[i][j+tt];
            if(j-tt>=0)
                dp1[i+1][j]|=dp1[i][j-tt];
        }
    }

    int z=0;
    z+=dp1[sz][lim+l];
    sz=y.size();
    for(int i=0;i<sz;i++)
    {
        int tt=y[i];
        for(int j=0;j<=2*lim;j++)
        {
            if(j+tt<=2*lim)
               dp2[i+1][j]|=dp2[i][j+tt];
            if(j-tt>=0)
                dp2[i+1][j]|=dp2[i][j-tt];
        }
    }

    z+=dp2[sz][lim+r];
    if(z==2)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    



}