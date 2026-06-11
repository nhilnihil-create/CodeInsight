#include <bits/stdc++.h>

#define IO  ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define endl '\n'
#define ll long long
#define f first
#define s second
#define mod 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int M=1e5+5;

int main()
{
    IO
    int n;
    ll a[M],m,sum[M]={},ans=0;
    map<ll,int>mp;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    sum[0]=a[0];
    for(int i=1;i<n;i++) {
       sum[i]=sum[i-1]+a[i];
    }
    for(int i=0;i<n;i++) {
        ans+=(mp[sum[i]%m]);
        mp[sum[i]%m]++;
    }
    cout<<ans+mp[0]<<endl;
    return 0;
}