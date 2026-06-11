#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int n;
    cin>>n;
    string u;
double ans=0,x;
for(int i=0;i<n;i++)
{
    cin>>x>>u;
    if(u=="BTC")
    {
        ans+=(x*(double)380000);
    }
    else
    ans+=x;
}
cout<<ans<<endl;
 
}