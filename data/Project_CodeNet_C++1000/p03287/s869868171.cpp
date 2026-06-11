#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 2*acos(0.0)
#define f first
#define s second
#define pb push_back
#define gap ' '
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define mod 1000000007
#define N 100005
ll n,m;
ll ara[N],sum[N];
map<ll,ll> mp;

int main(){
    fastio;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>ara[i];
        sum[i]=ara[i]+sum[i-1];
    }
    for(int i=0;i<=n;i++){
        sum[i]%=m;
        mp[sum[i]]++;
    }
    ll ans=0;
    for(int i=0;i<=n;i++){
        mp[sum[i]]--;
        ans+=mp[sum[i]];
    }
    cout<<ans<<endl;
}
