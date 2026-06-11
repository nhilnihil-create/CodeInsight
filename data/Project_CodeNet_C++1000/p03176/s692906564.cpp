#include<bits/stdc++.h>
#define ll long long
using namespace std;



ll get_max(vector<ll>& bit,int i)
{
    ll res=0;
    while(i>0)
    {
        res=max(res,bit[i]);
        i-=i & -i;
    }
    return res;
}

void update(int n,vector<ll>& bit,int i,ll x)
{
    ll res=x;
    while(i<=n)
    {
        bit[i]=max(res,bit[i]);
        i+=i & -i;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<ll>h(n),a(n);
    for(int i=0;i<n;i++)
        cin>>h[i];
    for(int i=0;i<n;i++)
        cin>>a[i];

    vector<ll>bit(n+1,0);

    for(int i=0;i<n;i++)
    {
        ll sum=get_max(bit,h[i]);
        update(n,bit,h[i],a[i]+sum);
    }
    cout<<get_max(bit,n);
}