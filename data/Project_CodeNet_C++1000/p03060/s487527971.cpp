#include<bits/stdc++.h>
#define lld long long int
#define pb push_back
#define in insert
#define mod 1000000007
#define pi 3.14159265358979

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    lld n;
    cin>>n;
    vector<lld>v(n),c(n),ans_v;
    for(lld i=0;i<n;i++)cin>>v[i];
    for(lld i=0;i<n;i++)cin>>c[i];
    for(lld i=0;i<n;i++)
    {
        ans_v.pb(v[i]-c[i]);
    }
    sort(ans_v.begin(),ans_v.end());
    //for(lld i=0;i<n;i++)cout<<ans_v[i]<<' ';cout<<"\n";
    lld ans=0;
    for(lld i=n-1;i>=0;i--)
    {
        if(ans_v[i]<0)break;
        ans+=ans_v[i];
    }
    cout<<ans<<"\n";
}
