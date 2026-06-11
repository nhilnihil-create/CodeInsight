#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    double ans=0;
    while(t--)
    {
        double n;
        string s;
        cin>>n>>s;
        if(s =="BTC")
        {
            ans+= ((380000)*n);
        }
        else
            ans+=n;
    }
    cout<<ans<<endl;
}
