#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll x,y,c=0;
    cin>>x>>y;
    if(x==y)
    {
        cout<<1<<endl;
        return 0;
    }
    while(x<=y)
    {
        x*=2;
        c++;
    }

   cout<<c<<endl;
}


