#include <bits/stdc++.h>

using namespace std;
const int N=5e5+5,mod=1e9+7;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ll INF=1e18;
    ll mn=INF;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        sum+=x;
        if(x>y) mn=min(mn,y);

    }
    if(mn==INF) mn=sum;
    cout<<sum-mn<<endl;
    return 0;
}
