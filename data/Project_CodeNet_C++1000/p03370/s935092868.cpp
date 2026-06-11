#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main()
{
    fast_io
    ll i,j,cnt=0,n,s;
    cin>>n>>s;
    ll x,mini=INT_MAX;
    for(i=0; i<n; i++)
    {
        cin>>x;
        mini=min(x,mini);
        if(x<=s)
        {
            cnt++;
            s-=x;
        }
    }
    if(cnt==n)
    {
        cnt+=(s/mini);
    }

    cout<<cnt<<endl;

    return 0;
}



