#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;


typedef pair<int,int> pa;

map<ll,int>mp;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    mp[0]=1;
    ll sum=0,ans=0;
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        sum=(sum+x)%m;
        ans+=mp[sum];
        mp[sum]++;
    }
    cout<<ans<<endl;
    return 0;
}
