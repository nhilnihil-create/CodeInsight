#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int x,v;
    cin>>x;
    vector<bool> ve(x+1);
    ve[1]=1;
    for(int i=2;i<=x;i++)
    {
        v=i*i;
        while(v<=x)
        {
            ve[v]=1;
            v*=i;
        }
    }
    
    for(int i=x;i>=1;i--)
    {
        if(ve[i])
        {
            cout<<i<<"\n";
            return 0;
        }
        
        
    }
}