#include <bits/stdc++.h>

using namespace std;
int main()
{
    int a,b,t;
    int ans=0,c;
    cin>>a>>b>>t;
    c=a;
    while(1)
    {
        if(c>t)
        {
            break;
        }
        ans +=b;
        c +=a;
    }
    cout<<ans<<endl;
}
