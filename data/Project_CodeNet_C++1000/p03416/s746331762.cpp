#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,b;
    cin>>a>>b;
    ll cnt=0;
    for(ll i=a;i<=b;i++)
    {
        ll aa=i/10000;
        ll bb=(i/1000)%10;
        //ll cc=(i/100)%10;
        ll cc=(i/10)%10;
        ll dd=i%10;
        if(aa==dd && bb==cc)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;



}
