#include<bits/stdc++.h>
#define int long long
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int32_t main()
{
    FastIO;
    int n,m,b,c;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;++i)
    cin>>a[i];
    vector<pair<int,int>>v(m);
    for(int i=0;i<m;++i)
    {
        cin>>b>>c;
        v.push_back(make_pair(c,b));
    }
    sort(a,a+n);
    sort(v.rbegin(),v.rend());
    int cnt=0,s=0,p=0;
    for(auto x:v)
    {
        int c=x.first;
        int b=x.second;
        cnt=0;
        for(int j=p;j<n;++j)
        {
            if(a[j]>=c||cnt>=b)
            break;
            if(a[j]<c&&cnt<b)
            {
                a[j]=c;
            }
            ++p;
            ++cnt;
        }
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        ans+=a[i];
    }
    cout<<ans;
}