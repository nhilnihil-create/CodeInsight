#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c,ans=0;
    cin>>a>>b>>c;
    if(c<=b)cout<<c+b<<endl;
    else
    {
        c-=b;
        ans+=2*b;
        if(c<=a)
        {
            ans+=c;
        }
        else
        {
            ans+=a;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}