#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll count1[101];
int main() {
    ll n;
    cin>>n;
    if(n<10)
    {
        cout<<"0";
        return 0;
    }
    for(ll i=2;i<=n;i++)
    {
        ll temp=i;
        for(ll j=2;j<=temp;j++)
        {
            while(temp%j==0)
            {
                count1[j]+=1;
                temp/=j;
            }
        }
    }
    ll ans=0;
    for(ll i=1;i<=100;i++)
    {
        if(count1[i]>=74)
        {
            ans+=1;
        }
    }
    vector<ll>v14;
    vector<ll>v4;
    vector<ll>v24;
    vector<ll>v2;
    for(ll i=1;i<=100;i++)
    {
        if(count1[i]>=2)
        {
            v2.push_back(i);
        }
        if(count1[i]>=4)
        {
            v4.push_back(i);
        }
        if(count1[i]>=14)
        {
            v14.push_back(i);
        }
        if(count1[i]>=24)
        {
            v24.push_back(i);
        }
    }
    set<pair<ll,ll>>s1;
    for(ll i=1;i<=100;i++)
    {
        if(count1[i]>=14)
        {
            for(ll j=1;j<=100;j++)
            {
                if(count1[j]>=4 && j!=i)
                {
                    ans+=1;
                   // s1.insert(make_pair(min(i,j),max(i,j)));
                }
            }
        }
    }
//    ans=ans+s1.size();
    s1.clear();
    for(ll i=1;i<=100;i++)
    {
        if(count1[i]>=24)
        {
            for(ll j=1;j<=100;j++)
            {
                if(count1[j]>=2 && j!=i)
                {
                    ans+=1;
                    //s1.insert(make_pair(min(i,j),max(i,j)));
                }
            }
        }
    }
  //  ans+=s1.size();
    set<tuple<ll,ll,ll>>s2;
    for(ll i=1;i<=100;i++)
    {
        if(count1[i]>=4)
        {
            for(ll j=i+1;j<=100;j++)
            {
                if(i!=j && count1[j]>=4)
                {
                    for(ll k=1;k<=100;k++)
                    {
                        if(k!=i && k!=j && count1[k]>=2)
                        {
                            ans+=1;
                            ll mini=min(i,j);
                            ll maxi=max(i,j);
                         //   s2.insert(make_tuple(min(mini,k),max(maxi,k),i+j+k-min(mini,k)-max(maxi,k)));
                        }
                    }
                }
            }
        }
    }
    cout<<ans;//+s2.size();
}