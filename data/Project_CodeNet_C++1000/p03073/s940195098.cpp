#include <bits/stdc++.h>
#include <fstream>
#include<string>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


typedef  long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;


#define endl "\n"
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const int N=3e5+5;
ll mod=998244353 ;
ll mul (ll a, ll b)
{
    a%=mod;
    b%=mod;
    return (a*b)%mod;
}
ll add (ll a, ll b)
{
    a%=mod;
    b%=mod;
    return (a+b+mod)%mod;
}
ll fastpow(ll b, ll p)
{
    if(p==0)
        return 1;
    ll ans=fastpow(b,p/2);
    ans=mul(ans,ans);
    if(p%2)ans=mul(ans,b);
    return ans;
}

int main()
{
    FIO
    string s;
    cin>>s;
    int co1=0,co2=0;
    for(int i=0;i<s.size();i++)
    {
        if(i%2==0)
        {
            if(s[i]=='1')
                co2++;
            else
                co1++;
        }
        else
        {
            if(s[i]=='1')
                co1++;
            else
                co2++;

        }

    }
    cout<<min(co1,co2);


    return 0;
}
