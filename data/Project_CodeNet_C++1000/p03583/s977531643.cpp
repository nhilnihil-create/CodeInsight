#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int main()
{
    ll n;
    cin>>n;
    for(ll x=1;x<=4000;x++)
    {
        for(ll y=x;y<=4000;y++)
        {
            ll p=4*x*y-(x+y)*n;
            if(p<=0)
            continue;
            ll q=x*y*n;
            if(q%p==0)
            {
                cout<<x<<" "<<y<<" "<<q/p<<endl;
                return 0;
            }
        }
    }

    
}