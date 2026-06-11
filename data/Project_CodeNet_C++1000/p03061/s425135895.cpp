#include<bits/stdc++.h>
#define int long long
using namespace std;
 

int mm1[100005];
int mm2[100004];


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

    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mm1[i]=__gcd(mm1[i-1],a[i]);
    }
    for(int i=n;i>=1;i--)
    {
        mm2[i]=__gcd(mm2[i+1],a[i]);
    }
    int mx=mm1[n];
    for(int i=1;i<=n;i++)
    {
        mx=max(mx,__gcd(mm1[i-1],mm2[i+1]));
    }
    cout<<mx;

}