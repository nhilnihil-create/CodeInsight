#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    ll n,k,ans=0;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        if(i-1<k)
            continue;
        ll pos=i-1;
        ll can=(i-k);
        ans+=(n/i)*can;
        ll rem=n%i;
        if(rem)
        {
            if(rem<k)
                continue;
            ans+=(rem-k);
            if(k)
                ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}
