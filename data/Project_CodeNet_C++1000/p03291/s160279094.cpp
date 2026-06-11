#include<bits/stdc++.h>
#define int long long
using namespace std;
 

int pp[100005];
const int mod=1e9+7;
int mm[3];

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

    pp[0]=1;
    for(int i=1;i<=100000;i++)
        pp[i]=pp[i-1]*3%mod;
    string a;
    cin>>a;
    int x=0,y=0,z=0;
    int tot=0;
    int n=a.length();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='A')
            mm[0]++;
        else if(a[i]=='B')
            mm[1]++;
        else if(a[i]=='C')
            mm[2]++;
        else
            tot++;
    }

    for(int i=0;i<n;i++)
    {
        if(a[i]=='A')
            x++;
        else if(a[i]=='C')
            y++;
        else if(a[i]=='?')
        {
            int tt1=(x*pp[z])%mod;
            if(z)
                tt1+=pp[z-1]*(z);
            tt1%=mod;
            int tt2=((mm[2]-y)*pp[tot-z-1])%mod;
            if(tot-z-2>=0)
                tt2+=pp[tot-z-2]*(tot-z-1)%mod;
            tt2%=mod;
            ans+=(tt1*tt2)%mod;
            ans%=mod;
            z++;
        }
        else
        {
            int tt1=(x*pp[z])%mod;
            if(z)
                tt1+=pp[z-1]*(z);
            tt1%=mod;
            int tt2=((mm[2]-y)*pp[tot-z])%mod;
            if(tot-z)
                tt2+=pp[tot-z-1]*(tot-z)%mod;
            tt2%=mod;
            ans+=(tt1*tt2)%mod;
            ans%=mod;
        }
    }
    
    cout<<ans;
}