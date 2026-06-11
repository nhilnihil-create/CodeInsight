#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

    ll n,i,j,x,y,sum=0,c=0;
    cin>>x>>y;
    if(x>y)
    {
        cout<<0<<endl;
        return 0;
    }
    else
    {
        c=1;
        sum=x;
    }
    while(sum<=y)
    {

        sum*=2;
        if(sum<=y)
            c++;
        else
            break;
    }
    cout<<c<<endl;
    return 0;
}
