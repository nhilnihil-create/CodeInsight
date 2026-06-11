#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
#define fast_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll a[N],dp[N];
bool vis[N],vis1[N];
vector<ll>v[N];
pair<ll,ll>p[N],p1[N];
set<int>s;
map<string,ll>mp;

main()
{fast_IO
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
        dp[1]=abs(a[1]-a[0]);
    for(int i=2; i<n; i++)
    {
        int s1=abs(a[i]-a[i-1]);
        int s2=abs(a[i]-a[i-2]);
        int ans=min(s1+dp[i-1],s2+dp[i-2]);
        dp[i]=ans;
    }
    cout<<dp[n-1];

}








