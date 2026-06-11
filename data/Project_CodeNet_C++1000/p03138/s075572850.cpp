#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;

typedef pair<ll,int>pa;

ll bit[50],a[N];

ll n,k,ans;

ll qpow (ll x, ll n)
{
    ll sum=1;
    while(n) {
        if(n&1) sum*=x;
        x*=x;
        n>>=1;
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);

   cin>>n>>k;

    for(int i=1;i<=n;i++) {
       cin>>a[i];
       ll x=a[i];
       int num=1;
       while(x){
        if(x&1) bit[num]++;
        num++;
        x>>=1;
       }
    }

    ll sum=0;

    for(int i=44;i>=0;i--){
        if(2*bit[i+1]<n && sum+(1ll<<i)<=k) sum+=(1ll<<i);
    }

    for(int i=1;i<=n;i++) {
        ans+=sum^a[i];
    }
    cout<<ans<<endl;
     return 0;
}
