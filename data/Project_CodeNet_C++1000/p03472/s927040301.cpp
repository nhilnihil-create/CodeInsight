#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,h;

    ll c=0;
    cin>>n>>h;
    vector<ll>v(n),v2(n);
    ll ma=0;
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
        cin>>v2[i];
        ma=max(ma,v[i]);
    }
    sort(v2.begin(),v2.end(),greater<ll>());
   // if(n==2)
    //{
    for(ll i=0;i<n;i++)
    {
        if(v2[i]>=ma)
        {
            h=h-v2[i];
            c=c+1;
            if(h<=0)
            {
                goto answer;
            }
        }
        else
        {
            break;
        }

    }
    if(h%ma==0)
    {
        c=c+(h/ma);
    }
    else{c=c+(h/ma)+1;}
    //}
    answer:
    cout<<c<<endl;

    }

