#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll h,w;
    cin>>h>>w;
    ll a[h+1][w+1];
    for(ll i=1;i<=h;i++)
    {
        for(ll j=1;j<=w;j++)
        {
            cin>>a[i][j];
        }
    }
    vector<pair<ll,ll>>v1;
    for(ll i=1;i<=h;i++)
    {
        for(ll j=1;j<w;j++)
        {
            if(a[i][j]%2==1)
            {
                v1.push_back(make_pair(i,j));
                a[i][j]-=1;
                a[i][j+1]+=1;
            }
        }
    }
    vector<pair<ll,ll>>v2;
    for(ll i=1;i<h;i++)
    {
        //cout<<a[i][w]<<endl;
        if(a[i][w]%2==1)
        {
            a[i][w]-=1;
            a[i+1][w]+=1;
            v2.push_back(make_pair(i,w));
        }
    }
    cout<<v1.size()+v2.size()<<endl;
    for(pair<ll,ll>i:v1)
    {
        cout<<i.first<<" "<<i.second<<" "<<i.first<<" "<<i.second+1<<endl;
    }
    for(pair<ll,ll>i:v2)
    {
        cout<<i.first<<" "<<i.second<<" "<<i.first+1<<" "<<i.second<<endl;
    }
}