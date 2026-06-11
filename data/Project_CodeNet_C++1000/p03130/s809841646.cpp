#include<bits/stdc++.h>
#define int long long
using namespace std;


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

    int x,y;
    int deg[5]={0};
    for(int i=0;i<3;i++)
    {
        cin>>x>>y;
        deg[x]++;
        deg[y]++;
    }
    sort(deg+1,deg+5);
    if(deg[1]==1 && deg[2]==1 && deg[3]==2 && deg[4]==2)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    

}