/* Jay Solanki */

#include <ext/pb_ds/assoc_container.hpp>
#include<bits/stdc++.h>
typedef long long int ll;
#define pii pair<ll, ll>
#define pb push_back
#define pf push_front
#define F first
#define S second
#define mp make_pair
#define For(i,a,b) for(ll i=a;i<b;i++)
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll mode = 1e9 + 7;

int modInverse(int a, int m)
{

    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
      return 0;
    while (a > 1)
    {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
       x += m0;
    return x;
}

ll power(ll x,ll y){
    ll res = 1;
    x = x % mode;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mode;
        y = y>>1;
        x = (x*x) % mode;
    }
    return res;
}

int main()
{
    FAST;
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,c=0,k=1,y=0,x=0,z=0;
        cin>>n;
        // string s;
        // cin>>s;
        vector<ll> v(n),ans(n);
        For(i,0,n) cin>>v[i];
        ans[0]=0;
        for(int i=1;i<n;i++)
        {
            if(i==1) ans[i]=abs(v[i-1]-v[i]);
            else
                ans[i]=min(ans[i-1]+abs(v[i]-v[i-1]),ans[i-2]+abs(v[i]-v[i-2]));
        }
        cout<<ans[n-1];
    }
    return 0;
}