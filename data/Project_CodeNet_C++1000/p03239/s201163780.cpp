#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,b,a)     for(int i=b;i>=a;i--)

int n,t,a,b,ans=INT_MAX;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>t;
    rep(i,1,n)
    {
        cin>>a>>b;
        if(b<=t)
            ans=min(ans,a);
    }
    if(ans!=INT_MAX)
        cout<<ans;
    else
        cout<<"TLE";
}

