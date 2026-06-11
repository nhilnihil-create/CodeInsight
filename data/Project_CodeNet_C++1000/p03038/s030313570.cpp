#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, m ;
ll ans ;
vector<pair<int,int> > v;
vector<int> a;
int main()
{
    IO
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    while(m--)
    {
        int b, c;
        cin>>b>>c;
        v.push_back({c,b});
    }
    sort(v.begin(),v.end());
    sort(a.rbegin(),a.rend());
    while(!v.empty())
    {
        int rem=v.back().second, c=v.back().first;
        v.pop_back();
        while(rem-- && !a.empty())
        {
            ans+=max(a.back(),c);
            a.pop_back();
        }
    }
    while(!a.empty())
    {
        ans+=a.back();
        a.pop_back();
    }
    cout<<ans;

}
