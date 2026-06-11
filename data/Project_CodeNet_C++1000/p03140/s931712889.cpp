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

    int n;
    cin>>n;
    string a,b,c;
    cin>>a>>b>>c;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        set<char>s;
        s.insert(a[i]);
        s.insert(b[i]);
        s.insert(c[i]);
        int sz=s.size();
        ans+=sz-1;
    }
    cout<<ans;
}
