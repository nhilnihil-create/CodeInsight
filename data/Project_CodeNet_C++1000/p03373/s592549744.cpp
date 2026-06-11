#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;

    long long r=0;

    if(a+b>2*c)
    {
        long long v=min(x,y);
        x-=v;
        y-=v;
        r+=2*c*v;
    }
    if(x>0)
    {
        if(a>2*c)
        {
            r+=2*c*x;
            y-=x;
            x=0;
        }
        else
        {
            r+=a*x;
            x=0;
        }
    }
    if(y>0)
    {
        if(b>2*c)
        {
            r+=2*c*y;
            x-=y;
            y=0;
        }
        else
        {
            r+=b*y;
            y=0;
        }
    }
    cout<<r<<endl;

    return 0;
}
